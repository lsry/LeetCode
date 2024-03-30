#include <array>
#include <vector>
using std::vector;

class Solution {
    constexpr static std::array<std::array<int, 2>, 3> indics{{{-1, -1}, {0, -1}, {1, -1}}};
public:
    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N, -1));
        for (int i = 0;i < M;++i) {
            dp[i][0] = 0;
        }
        int ans{0};
        for (int j = 1;j < N;++j) {
            for (int i = 0;i < M;++i) {
                for (std::array<int, 2> const &idx : indics) {
                    int nx{i + idx[0]}, ny{j + idx[1]};
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] < grid[i][j] && dp[nx][ny] != -1) {
                        dp[i][j] = std::max(dp[i][j], dp[nx][ny] + 1);
                        ans = std::max(dp[i][j], ans);
                    }
                }
            }
        }
        return ans;
    }
};