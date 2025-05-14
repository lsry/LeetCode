#include <array>
#include <string>
using std::string;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int lengthAfterTransformations(string s, int t) {
        std::array<std::array<unsigned long long int, 26>, 2> dp{{0ULL}};
        int curIndex{0};
        for (char c : s) {
            dp[curIndex][c - 'a'] += 1;
        }
        for (int i = 0;i < t;++i) {
            int nextIndex = 1 - curIndex;
            for (int j = 0;j < 26;++j) {
                if (j > 1) {
                    dp[nextIndex][j] = dp[curIndex][j - 1];
                } else if (j == 1) {
                    dp[nextIndex][j] = (dp[curIndex][j - 1] + dp[curIndex][25]) % MOD;
                } else {
                    dp[nextIndex][j] = dp[curIndex][25];
                }
            }
            curIndex = nextIndex;
        }
        unsigned long long int sum{0ULL};
        for (unsigned long long int num : dp[curIndex]) {
            sum = (sum + num) % MOD;
        }
        return static_cast<int>(sum);
    }
};