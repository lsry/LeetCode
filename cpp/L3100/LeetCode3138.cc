#include <array>
#include <string>
using std::string;

class Solution {
    bool checkRegular(string const &s, std::array<int, 26> const &single, int sz) {
        for (int i = 0;i < s.size();i += sz) {
            std::array<int, 26> curBits{0};
            for (int j = 0;j < sz;++j) {
                curBits[s[i + j] - 'a'] += 1;
            }
            for (int j = 0;j < 26;++j) {
                if (single[j] != curBits[j]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int minAnagramLength(string s) {
        std::array<int, 26> counts{0};
        for (char const c : s) {
            counts[c - 'a'] += 1;
        }
        std::array<int, 26> single{0};
        int ans{0};
        for (int i = 0;i < s.size();++i) {
            single[s[i] - 'a'] += 1;
            bool check{true};
            int mod{0};
            for (int j = 0;j < 26;++j) {
                if (counts[j] == 0) {
                    continue;
                } else if (single[j] == 0 || counts[j] % single[j] != 0 || (mod > 0 && (counts[j] / single[j]) != mod)) {
                    check = false;
                    break;
                } else {
                    if (mod == 0) {
                        mod = counts[j] / single[j];
                    }
                }
            }
            if (check && checkRegular(s, single, i + 1)) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};