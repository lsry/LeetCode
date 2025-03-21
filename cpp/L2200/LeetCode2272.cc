#include <limits>
#include <string>
using std::string;

class Solution {
    int maxVariance(string const &s, char a, char b) {
        int ans{0};
        int f0{0}, f1{std::numeric_limits<int>::min()};
        for (char c : s) {
            if (c == a) {
                f1 += 1;
                f0 = std::max(f0, 0) + 1;
            } else if (c == b) {
                f0 = std::max(f0, 0) - 1;
                f1 = f0;
            }
            ans = std::max(ans, f1);
        }
        return ans;
    }
public:
    int largestVariance(string s) {
        int ans{0};
        for (char c{'a'};c <= 'z';++c) {
            for (char d{'a'};d <= 'z';++d) {
                if (c != d) {
                    int x = maxVariance(s, c, d);
                    ans = std::max(x, ans);
                }
            }
        }
        return ans;
    }
};