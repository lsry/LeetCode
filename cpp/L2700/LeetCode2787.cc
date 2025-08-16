#include <vector>
class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};

    unsigned long long int powX(int v, int x) {
        unsigned long long int value{1ULL};
        for (int i = 0;i < x;++i) {
            value *= v;
        }
        return value;
    }
public:
    int numberOfWays(int n, int x) {
        std::vector<unsigned long long int> dp(n + 1, 0ULL);
        dp[0] = 1ULL;
        for (int i = 1;i <= n;++i) {
            unsigned long long int ix{powX(i, x)};
            if (ix > n) {
                break;
            }
            for (int j = n;j >= ix;--j) {
                dp[j] = (dp[j] + dp[j - ix]) % MOD;
            }
        }
        return dp[n];
    }
};