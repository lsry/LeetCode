#include <vector>

class Solution {
public:
    double soupServings(int n) {
        if (n >= 4900) {
            return 1.0;
        }
        n = n % 25 == 0 ? n / 25 : n / 25 + 1;
        std::vector<std::vector<double>> dp(n + 1, std::vector<double>(n + 1, 0.0));
        dp[0][0] = 0.5;
        for (int j = 1;j <= n;++j) {
            dp[0][j] = 1.0;
        }
        for (int i = 1;i <= n;++i) {
            for (int j = 1;j <= n;++j) {
                double v1{dp[std::max(i - 4, 0)][j]};
                double v2{dp[std::max(i - 3, 0)][std::max(j - 1, 0)]};
                double v3{dp[std::max(i - 2, 0)][std::max(j - 2, 0)]};
                double v4{dp[std::max(i - 1, 0)][std::max(j - 3, 0)]};
                dp[i][j] = (v1 + v2 + v3 + v4) * 0.25;
            }
        }
        return dp[n][n];
    }
};