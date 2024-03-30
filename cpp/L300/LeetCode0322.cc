#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        std::sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (long long coin : coins) {
            for (long long a = 1;a <= amount;++a) {
                for (long long i = 1;i * coin <= a;++i) {
                    long long rem = a - i * coin;
                    if (dp[rem] != -1) {
                        if (dp[a] == -1) {
                            dp[a] = i + dp[rem];
                        } else {
                            dp[a] = std::min(dp[a], static_cast<int>(i + dp[rem]));
                        }
                    }  
                }
            }
        }
        return dp[amount];
    }
};