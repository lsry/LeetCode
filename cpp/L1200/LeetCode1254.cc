#include <vector>
using std::vector;
#include <queue>
#include <array>

class Solution {
    constexpr static std::array<std::array<int, 2>, 4> indics{{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
    int M, N;
    bool checkClosed(vector<vector<int>>& grid, vector<vector<bool>> &visited, int x, int y) {
        bool closed{true};
        std::queue<std::pair<int, int>> q;
        q.emplace(std::make_pair(x, y));
        visited[x][y] = true;
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            visited[cx][cy] = true;
            for (std::array<int, 2> const &index : indics) {
                int nx{cx + index[0]}, ny{cy + index[1]};
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                    closed = false;
                } else if (grid[nx][ny] == 0 && !visited[nx][ny]) {
                    q.emplace(std::make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        return closed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans{0};
        M = grid.size(), N = grid[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (checkClosed(grid, visited, i, j)) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};