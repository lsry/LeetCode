#include <string>
using std::string;

class Solution {
public:
    int getLucky(string s, int k) {
        int ans{0};
        for (char const c : s) {
            int n = c - 'a' + 1;
            if (n >= 10) {
                ans += n / 10 + n % 10;
            } else {
                ans += n;
            }
        }
        for (int i = 1;i < k && ans >= 10;++i) {
            int t = 0;
            while (ans > 0) {
                t += ans % 10;
                ans /= 10;
            }
            ans = t;
        }
        return ans;
    }
};