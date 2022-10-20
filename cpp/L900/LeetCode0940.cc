#include <string>
using std::string;

#include <array>

class Solution {
    constexpr static long long int MOD = 1000000007;
public:
    int distinctSubseqII(string s) {
        std::array<long long int, 26> dp{{0LL}};
        for (char const &c : s) {
            int id = c - 'a';
            dp[id] = (dp[id] + 1) % MOD;
            for (int i = 0;i < 26;++i) {
                if (i == id) {
                    continue;
                }
                dp[id] = (dp[id] + dp[i]) % MOD;
            }
        }
        long long int sum{0LL};
        for (int i = 0;i < 26;++i) {
            sum = (sum + dp[i]) % MOD;
        }
        return (int)(sum % MOD);
    }
};