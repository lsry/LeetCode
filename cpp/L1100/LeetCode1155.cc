#include <vector>

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n * k) {
            return 0;
        }
        std::vector<std::vector<unsigned long long int>> dp(n, std::vector<unsigned long long int>(target + 1, 0ULL));
        for (int i = 1;i <= std::min(target, k);++i) {
            dp[0][i] = 1LL;
        }
        for (int i = 1;i < n;++i) {
            for (int j = (i + 1);j <= target;++j) {
                for (int m = 1;m <= k && j - m > 0;++m) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - m]) % MOD;
                }
            }
        }
        return dp[n - 1][target];
    }
};