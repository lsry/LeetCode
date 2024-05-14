#include <array>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    constexpr static std::array<std::array<int, 2>, 4> indics{{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int raw{0};
        std::queue<std::pair<int, int>> q;
        int M = grid.size(), N = grid[0].size();
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 1) {
                    ++raw;
                } else if (grid[i][j] == 2) {
                    q.push(std::pair<int, int>(i, j));
                }
            }
        }
        int time = 0;
        while (!q.empty() && raw > 0) {
            int sz = q.size();
            for (int i = 0;i < sz;++i) {
                auto [x, y] = q.front();
                q.pop();
                for (std::array<int, 2> const &idx : indics) {
                    int nx{idx[0] + x}, ny{idx[1] + y};
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == 1) {
                        --raw;
                        grid[nx][ny] = 2;
                        q.push(std::pair<int, int>(nx, ny));
                    }
                }
            }
            ++time;
        }
        return raw == 0 ? time : -1;
    }
};