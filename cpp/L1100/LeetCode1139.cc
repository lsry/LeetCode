#include <vector>
using std::vector;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(2, 0)));
        int ans{0};
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                dp[i][j][0] = 1;
                dp[i][j][1] = 1;
                if (i - 1 >= 0) {
                    dp[i][j][0] += dp[i - 1][j][0];
                }
                if (j - 1 >= 0) {
                    dp[i][j][1] += dp[i][j - 1][1];
                }
                for (int k = std::min(dp[i][j][0], dp[i][j][1]);k > 0 && k * k > ans;--k) {
                    int ri = i - k + 1;
                    int bj = j - k + 1;
                    if (dp[ri][j][1] >= k && dp[i][bj][0] >= k) {
                        ans = std::max(ans, k * k);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
