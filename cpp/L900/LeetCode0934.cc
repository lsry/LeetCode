#include <vector>
using std::vector;

#include <queue>
#include <array>

class Solution {
private:
    constexpr static std::array<std::array<int, 2>, 4> indics{{{0, -1}, {-1, 0}, {0, 1}, {1, 0}}};
    int N{0};
    void dfs(vector<vector<int>>& grid, std::queue<int> &q, int x, int y) {
        if (x < 0 || x >= N || y < 0 || y >= N || grid[x][y] != 1) {
            return;
        }
        q.push(x * N + y);
        grid[x][y] = 2;
        for (std::array<int, 2> const &id : indics) {
            dfs(grid, q, x + id[0], y + id[1]);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        N = grid.size();
        if (N <= 1) {
            return 0;
        }
        std::queue<int> q;
        for (int i = 0;i < N;++i) {
            bool flag{false};
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, q, i, j);
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        int count{0};
        while (!q.empty()) {
            ++count;
            std::size_t qz{q.size()};
            for (std::size_t i{0};i < qz;++i) {
                int num = q.front();
                int x{num / N}, y{num % N};
                q.pop();
                for (std::array<int, 2> const &id : indics) {
                    int nx{x + id[0]}, ny{y + id[1]};
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        if (grid[nx][ny] == 1) {
                            return count;
                        } else if (grid[nx][ny] == 0) {
                            q.push(nx * N + ny);
                            grid[nx][ny] = 3;
                        }
                    }
                }
            }
        }
        return -1;
    }
};