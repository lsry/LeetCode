#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<bool>> dp(N, vector<bool>(1024, false));
        dp[0][0] = true;
        vector<bool> tp(1024, false);
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                std::fill(tp.begin(), tp.end(), false);
                for (int k = 0;k < 1024;++k) {
                    if (dp[j][k] || (j > 0 && dp[j - 1][k])) {
                        tp[k ^ grid[i][j]] = true;
                    }
                }
                for (int k = 0;k < 1024;++k) {
                    dp[j][k] = tp[k];
                }
            }
        }
        for (int i = 0;i < 1024;++i) {
            if (dp[N - 1][i]) {
                return i;
            }
        }
        return -1;
    }
};
