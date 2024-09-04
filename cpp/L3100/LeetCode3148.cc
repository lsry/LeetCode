#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int M = grid.size(), N = grid[0].size();
        int ans = std::numeric_limits<int>::min();
        vector<vector<int>> scores(M, vector<int>(N, 0));
        for (int i = 0;i < M;++i) {
            for (int j = N - 1;j >= 0;--j) {
                if (i - 1 >= 0) {
                    scores[i][j] = (scores[i - 1][j] < 0 ? 0 : scores[i - 1][j]) + grid[i][j] - grid[i - 1][j];
                    for (int k = i - 2;k >= 0;--k) {
                        scores[i][j] = std::max(scores[i][j], (scores[k][j] < 0 ? 0 : scores[k][j]) + grid[i][j] - grid[k][j]);
                    }
                    ans = std::max(ans, scores[i][j]);
                }
                if (j - 1 >= 0) {
                    int v = (scores[i][j - 1] < 0 ? 0 : scores[i][j - 1]) + grid[i][j] - grid[i][j - 1];
                    for (int k = j - 2;k >= 0;--k) {
                        v = std::max(v, (scores[i][k] < 0 ? 0 : scores[i][k]) + grid[i][j] - grid[i][k]);
                    }
                    if (i - 1 >= 0) {
                        scores[i][j] = std::max(v, scores[i][j]);
                    } else {
                        scores[i][j] = v;
                    }
                    ans = std::max(ans, scores[i][j]);
                }
            }
        }
        return ans;
    }
};