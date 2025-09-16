#include <cctype>
#include <string>
#include <unordered_map>
using std::string;
#include <vector>
using std::vector;

class Solution {
    string toUpperStr(string word) {
        for (char &c : word) {
            c = std::toupper(c);
        }
        return word;
    }

    string toNoVowel(string word) {
        for (char &c : word) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                c = '*';
            }
        }
        return word;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        std::unordered_map<string, string> matched, largeMatched, vowelMatched;
        for (string const &word : wordlist) {
            matched.insert({word, word});
            string up = toUpperStr(word);
            if (!largeMatched.contains(up)) {
                largeMatched.insert({up, word});
            }
            string noVowel = toNoVowel(up);
            if (!vowelMatched.contains(noVowel)) {
                vowelMatched.insert({noVowel, word});
            }
        }
        vector<string> ans;
        ans.reserve(queries.size());
        for (string const &query : queries) {
            if (matched.contains(query)) {
                ans.push_back(query);
                continue;
            } 
            string up = toUpperStr(query);
            if (largeMatched.contains(up)) {
                ans.emplace_back(largeMatched[up]);
                continue;
            }
            string noVowel = toNoVowel(up);
            if (vowelMatched.contains(noVowel)) {
                ans.emplace_back(vowelMatched[noVowel]);
            } else {
                ans.emplace_back("");
            }
        }
        return ans;
    }
};