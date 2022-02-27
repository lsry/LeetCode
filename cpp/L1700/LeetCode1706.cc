#include <vector>
using std::vector;

#include <array>
using std::array;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<array<int, 2>>> dp(M, vector<array<int, 2>>(N));
        for (int j = 0;j < N;++j) {
            if (grid[M - 1][j] == 1) {
                if (j + 1 >= N || grid[M - 1][j + 1] == -1) {
                    dp[M - 1][j][0] = -1;
                } else {
                    dp[M - 1][j][0] = j + 1;
                }
                dp[M - 1][j][1] = j;
            } else {
                if (j - 1 < 0 || grid[M - 1][j - 1] == 1) {
                    dp[M - 1][j][0] = -1;
                } else {
                    dp[M - 1][j][0] = j - 1;
                }
                dp[M - 1][j][1] = j;
            }
        }
        for (int i = M - 2;i >= 0;--i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 1) {
                    if (j + 1 >= N ||grid[i][j + 1] == -1) {
                        dp[i][j][0] = -1;
                    } else {
                        dp[i][j][0] = dp[i + 1][j + 1][0];
                    }
                    if (i >= M) {
                        dp[i][j][1] = j;
                    } else {
                        dp[i][j][1] = dp[i + 1][j][0];
                    }
                } else {
                    if (j - 1 < 0 || grid[i][j - 1] == 1) {
                        dp[i][j][0] = -1;
                    } else {
                        dp[i][j][0] = dp[i + 1][j - 1][0];
                    }
                    if (i >= M) {
                        dp[i][j][1] = j;
                    } else {
                        dp[i][j][1] = dp[i + 1][j][0];
                    }
                }
            }
        }
        vector<int> res;
        for (int j = 0;j < N;++j) {
            res.push_back(dp[0][j][0]);
        }
        return res;
    }
};