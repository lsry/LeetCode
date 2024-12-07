#include <string>
using std::string;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int one{0}, zero{0};
        int ans{0};
        for (int i = 0,j = 0;j < s.size();++j) {
            if (s[j] == '0') {
                ++zero;
            } else {
                ++one;
            }
            if (zero > k || one > k) {
                while (zero > k && one > k) {
                    if (s[i] == '0') {
                        --zero;
                    } else {
                        --one;
                    }
                    ++i;
                }
            }
            ans += j - i + 1;
        }      
        return ans;
    }
};