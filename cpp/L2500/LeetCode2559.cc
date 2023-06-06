#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
    bool vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool vowelWord(string const &word) {
        return vowel(word[0]) && vowel(word.back());
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size();
        vector<int> pres(N + 1, 0);
        for (int i = 1;i <= N;++i) {
            pres[i] = (vowelWord(words[i - 1]) ? 1 : 0) + pres[i - 1];
        }      
        vector<int> res(queries.size(), 0);
        for (int i = 0;i < queries.size();++i) {
            res[i] = pres[queries[i][1] + 1] - pres[queries[i][0]];
        }
        return res;
    }
};