#include <vector>
class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int numberOfSets(int n, int k) {
        std::vector<unsigned long long int> dp(n + 1, 1), preSum(n + 1, 0);
        for (int i = 1;i <= n;++i) {
            preSum[i] = (preSum[i - 1] + dp[i]) % MOD;
        }
        for (int i = 1;i <= k;++i) {
            dp[0] = 0;
            for (int j = 1;j <= n;++j) {
                dp[j] = (dp[j - 1] + preSum[j - 1]) % MOD;
            }
            preSum[0] = 0;
            for (int j = 1;j <= n;++j) {
                preSum[j] = (preSum[j - 1] + dp[j]) % MOD;
            }
        }
        return dp[n];
    }
};
