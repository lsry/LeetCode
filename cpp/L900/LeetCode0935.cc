#include <vector>

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int knightDialer(int n) {
        std::vector<unsigned long long int> dp(10, 1ULL), tp(10, 0ULL);
        for (int i = 2;i <= n;++i) {
            tp[0] = (dp[4] + dp[6]) % MOD;
            tp[1] = (dp[6] + dp[8]) % MOD;
            tp[2] = (dp[7] + dp[9]) % MOD;
            tp[3] = (dp[4] + dp[8]) % MOD;
            tp[4] = (dp[0] + dp[3] + dp[9]) % MOD;
            tp[5] = 0;
            tp[6] = (dp[0] + dp[1] + dp[7]) % MOD;
            tp[7] = (dp[2] + dp[6]) % MOD;
            tp[8] = (dp[1] + dp[3]) % MOD;
            tp[9] = (dp[2] + dp[4]) % MOD;
            for (int j = 0;j < 10;++j) {
                dp[j] = tp[j];
            }
        }
        unsigned long long int ans{0ULL};
        for (int i = 0;i < 10;++i) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};