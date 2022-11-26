#include <vector>

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        std::vector<double> dp(query_row + 1, 0.0);
        dp[0] = static_cast<double>(poured);
        for (int i{1};i <= query_row;++i) {
            for (int j{i};j >= 0;--j) {
                double tv{dp[j] <= 1.0 ? 0.0 : dp[j] - 1.0};
                double lv{(j - 1 < 0 || dp[j - 1] <= 1.0) ? 0.0 : dp[j - 1] - 1.0};
                dp[j] = (tv + lv) * 0.5;
            }
        }
        return std::min(1.0, dp[query_glass]);
    }
};