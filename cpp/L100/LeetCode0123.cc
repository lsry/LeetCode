#include <algorithm>
#include <array>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        std::array<std::array<int, 2>, 3> dp{{{0 ,-1000000}, {0 ,-100000000}, {0, -100000000}}};
        for (int price : prices) {
            int t01 = std::max(dp[0][1], dp[0][0] - price);
            int t10 = std::max(dp[1][0], price + dp[0][1]);
            int t11 = std::max(dp[1][1], dp[1][0] - price);
            int t20 = std::max(dp[2][0], price + dp[1][1]);
            int t21 = std::max(dp[2][1], dp[2][0] - price);
            dp[0][1] = t01;
            dp[1][0] = t10;
            dp[1][1] = t11;
            dp[2][0] = t20;
            dp[2][1] = t21;
        }
        int profit = 0;
        for (std::array<int, 2> const &at : dp) {
            for (int x : at) {
                profit = std::max(x, profit);
            }
        }
        return profit;
    }
};