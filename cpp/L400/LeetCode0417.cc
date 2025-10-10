#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <array>

class Solution {
    std::array<std::array<int, 2>, 4> pos{{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        if (m == 0 || n == 0) {
            return res;
        }
        queue<std::pair<int, int>> bq;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0;i < n;++i) {
            grid[0][i] = 1;
            bq.push({0, i});
        }
        for (int j = 1;j < m;++j) {
            grid[j][0] = 1;
            bq.push({j, 0});
        }
        while (!bq.empty()) {
            std::pair<int, int> node = bq.front();
            bq.pop();
            int cx = node.first;
            int cy = node.second;
            for (std::array<int, 2> ar : pos) {
                int nx = cx + ar[0];
                int ny = cy + ar[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0 && heights[nx][ny] >= heights[cx][cy]) {
                    grid[nx][ny] = 1;
                    bq.push({nx, ny});
                }
            }
        }
        vector<vector<int>> gridTWO(m, vector<int>(n));
        for (int i = 0;i < m;++i) {
            gridTWO[i][n - 1] = 1;
            bq.push({i, n - 1});
        }
        for (int j = 0;j < n - 1;++j) {
            gridTWO[m - 1][j] = 1;
            bq.push({m - 1, j});
        }
        while (!bq.empty()) {
            std::pair<int, int> node = bq.front();
            bq.pop();
            int cx = node.first;
            int cy = node.second;
            for (const std::array<int, 2> &ar : pos) {
                int nx = cx + ar[0];
                int ny = cy + ar[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && gridTWO[nx][ny] == 0 && heights[nx][ny] >= heights[cx][cy]) {
                    gridTWO[nx][ny] = 1;
                    bq.push({nx, ny});
                }
            }
        }
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                if (grid[i][j] == 1 && gridTWO[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> vec{{1,2,3},{8, 9, 4}, {7, 6, 5}};
    Solution s;
    s.pacificAtlantic(vec);
}