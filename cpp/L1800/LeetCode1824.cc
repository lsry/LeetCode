#include <vector>
using std::vector;
#include <numeric>

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        std::size_t N{obstacles.size()};
        vector<vector<int>> dp(N, vector<int>(3, 0x3f3f3f3f));
        dp[0][0] = 1, dp[0][1] = 0, dp[0][2] = 1;
        for (std::size_t i{1};i < N;++i) {
            int ob = obstacles[i];
            for (int j = 0;j < 3;++j) {
                if (obstacles[i - 1] != j + 1 && ob != j + 1) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            int a = dp[i][0], b = dp[i][1], c = dp[i][2];
            if (ob != 1) {
                if (ob != 2) {
                    dp[i][1] = std::min(dp[i][1], a + 1);
                }
                if (ob != 3) {
                    dp[i][2] = std::min(dp[i][2], a + 1);
                }
            }
            if (ob != 2) {
                if (ob != 1) {
                    dp[i][0] = std::min(dp[i][0], b + 1);
                }
                if (ob != 3) {
                    dp[i][2] = std::min(dp[i][2], b + 1);
                }
            }
            if (ob != 3) {
                if (ob != 1) {
                    dp[i][0] = std::min(dp[i][0], c + 1);
                }
                if (ob != 2) {
                    dp[i][1] = std::min(dp[i][1], c + 1);
                }
            }
        }
        return std::min(dp[N - 1][0], std::min(dp[N - 1][1], dp[N - 1][2]));
    }
};