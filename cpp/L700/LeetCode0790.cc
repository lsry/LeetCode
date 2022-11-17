#include <vector>

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};
public:
    int numTilings(int n) {
        std::vector<std::vector<unsigned long long int>> dp(n + 1, std::vector(4, 0ULL));
        dp[0][3] = 1ULL;
        for (int i = 1;i <= n;++i) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
            dp[i][2] = (dp[i - 1][2] + dp[i - 1][0]) % MOD;
            for (int j = 0;j < 4;++j) {
                dp[i][3] = (dp[i][3] + dp[i - 1][j]) % MOD;
            }
        }
        return (int)dp[n][3];
    }
};