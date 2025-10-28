#include <array>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
    bool sameSource(string const &s1, string const &s2) {
        std::array<int, 26> a1{0}, a2{0};
        for (char c : s1) {
            a1[c - 'a']++;
        }
        for (char c : s2) {
            a2[c - 'a']++;
        }
        for (int i = 0;i < 26;++i) {
            if (a1[i] != a2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for (string word : words) {
            if (ans.empty() || !sameSource(ans.back(), word)) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};