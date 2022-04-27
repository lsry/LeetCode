#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <unordered_map>
using std::unordered_map;

#include <algorithm>

#include <string>
using std::string;

class Solution {
private:
    bool isLetter(char ch) {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> map;
        std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        unordered_set<string> strSet;
        for (string banWord : banned) {
            std::transform(banWord.begin(), banWord.end(), banWord.begin(), ::tolower);
            strSet.emplace(banWord);
        }
        std::size_t sz = paragraph.size();
        for (std::size_t i = 0;i < sz;) {
            while (i < sz && !isLetter(paragraph[i])) {
                ++i;
            }
            if (i >= sz) {
                break;
            }
            string word;
            while (i < sz && isLetter(paragraph[i])) {
                word += paragraph[i];
                ++i;
            }
            map[word] += 1;
        }
        int count = 0;
        string res;
        for (std::pair<string, int> p : map) {
            if (p.second >= count && strSet.find(p.first) == strSet.end()) {
                res = p.first;
                count = p.second;
            }
        }
        return res;
    }
};