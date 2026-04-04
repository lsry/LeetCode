#include <string>
using std::string;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int zero{0}, one{0};
        int n = s.size();
        int ans{0};
        for (int i = 0;i < n;++i) {
            int j{i};
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            int c{j - i};
            if (s[i] == '0') {
                if (one > 0) {
                    ans += std::min(c, one);
                }
                zero = c;
            } else {
                if (zero > 0) {
                    ans += std::min(c, zero);
                }
                one = c;
            }
            i = j - 1;
        }
        return ans;
    }
};
