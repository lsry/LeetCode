#include <array>

class Solution {
public:
    int countVowelStrings(int n) {
        if (n <= 0) {
            return 0;
        }
        std::array<int, 5> dp;
        std::fill(dp.begin(), dp.end(), 1);
        int sum{5};
        for (int i{2};i <= n;++i) {
            int cur{sum}, last{0};
            sum = 0;
            for (int j{0};j < 5;++j) {
                last = dp[j];
                dp[j] = cur;
                cur -= last;
                sum += dp[j];
            }
        }
        return sum;
    }
};