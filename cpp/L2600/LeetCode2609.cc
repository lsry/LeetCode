#include <string>
using std::string;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans{0}, sz = s.size();
        for (int i{0};i < sz;++i) {
            if (s[i] == '0') {
                int j{i};
                while (j < sz && s[j] == '0') {
                    ++j;
                }
                int zero{j - i};
                i = j;
                while (j < sz && s[j] == '1') {
                    ++j;
                }
                int one{j - i};
                ans = std::max(ans, std::min(zero, one) * 2);
                i = j - 1;
            }
        }
        return ans;
    }
};