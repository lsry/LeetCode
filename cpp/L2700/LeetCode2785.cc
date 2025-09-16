#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
using std::string;

class Solution {
    bool isVowl(char c) {
        c = std::tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string sortVowels(string s) {
        std::vector<int> idx;
        std::vector<char> alphs;
        for (int i = 0;i < s.size();++i) {
            if (isVowl(s[i])) {
                idx.push_back(i);
                alphs.push_back(s[i]);
            }
        }      
        std::sort(alphs.begin(), alphs.end());
        for (int i = 0;i < idx.size();++i) {
            s[idx[i]] = alphs[i];
        }
        return s;
    }
};