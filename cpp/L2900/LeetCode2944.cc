#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int N = prices.size();
        vector<int> dp(N + 1, std::numeric_limits<int>::max());
        dp[N] = 0;
        for (int i = N - 1;i >= 0;--i) {
            int minX = std::numeric_limits<int>::max();
            for (int j = i + 1;j <= N && j <= i + i + 2;++j) {
                minX = std::min(minX, dp[j]);
            }
            dp[i] = minX + prices[i];
        }      
        return dp[0];
    }
};