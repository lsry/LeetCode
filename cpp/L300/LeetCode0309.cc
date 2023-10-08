#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N  =  prices.size();
        if (N < 2) {
            return 0;
        }
        vector<vector<int>> dp(2, vector<int>(N + 2, 0));
        std::fill(dp[0].begin(), dp[0].end(), std::numeric_limits<int>::min());
        for (int i = 0;i < N;++i) {
            dp[0][i + 2] = std::max(dp[0][i + 1], dp[1][i] - prices[i]);
            dp[1][i + 2] = std::max(dp[1][i + 1], dp[0][i + 1] + prices[i]);
        }
        return std::max(dp[0][N + 1], dp[1][N + 1]);
    }
};