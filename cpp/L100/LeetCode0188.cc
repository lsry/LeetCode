#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));
        for (int i = 0;i <= k;++i) {
            dp[i][1] = std::numeric_limits<int>::min();
        }
        for (int price : prices) {
            for (int i = k;i >= 1;--i) {
                int t = dp[i][0];
                dp[i][0] = std::max(dp[i][0], dp[i - 1][1] + price);
                dp[i][1] = std::max(dp[i][1], t - price);
            }
            dp[0][1] = std::max(dp[0][1], -price);
        }
        int profit{0};
        for (int i = 0;i <= k;++i) {
            profit = std::max(profit, std::max(dp[i][0], dp[i][1]));
        }
        return profit;
    }
};