#include <vector>
using std::vector;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int max = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                if (grid[i][j] > 0) {
                    int r = dfs(grid, i, j, 0);
                    max = std::max(max, r);
                }
            }
        }
        return max;
    }

private:
    int dfs(vector<vector<int>> &grid, int x, int y, int step) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || step > 26 || grid[x][y] == 0) {
            return 0;
        }
        int t = grid[x][y];
        grid[x][y] = 0;
        int r1 = dfs(grid, x + 1, y, step + 1);
        int r2 = dfs(grid, x - 1, y, step + 1);
        int r3 = dfs(grid, x, y - 1, step + 1);
        int r4 = dfs(grid, x, y + 1, step + 1);
        grid[x][y] = t;
        return std::max({r1, r2, r3, r4}) + t;
    }
};