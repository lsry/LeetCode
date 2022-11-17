#include <vector>
using std::vector;

#include <string>
using std::string;

#include <array>
#include <tuple>
#include <queue>

class Solution {
    constexpr static std::array<std::array<int, 2>, 4> indics{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int M = grid.size(), N = grid[0].size();
        int sx{0}, sy{0};
        int keyCount{0};
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    ++keyCount;
                }
            }
        }
        vector<vector<vector<int>>> dist(M, vector<vector<int>>(N, vector<int>((1 << keyCount), -1)));
        dist[sx][sy][0] = 0;
        std::queue<std::tuple<int, int, int>> q;
        q.push({sx, sy, 0});
        while (!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();
            if (mask == (1 << keyCount) - 1) {
                return dist[x][y][mask];
            }
            for (std::array<int, 2> const &ids : indics) {
                int nx{ids[0] + x};
                int ny{ids[1] + y};
                if (nx < 0 || nx >= M || ny < 0 || ny >= N || grid[nx][ny] == '#') {
                    continue;
                } else if (grid[nx][ny] == '.' || grid[nx][ny] == '@') {
                    if (dist[nx][ny][mask] == -1) {
                        dist[nx][ny][mask] = dist[x][y][mask] + 1;
                        q.push({nx, ny, mask});
                    }
                } else if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                    int nm{mask | (1 << (grid[nx][ny] - 'a'))};
                    if (dist[nx][ny][nm] == -1) {
                        dist[nx][ny][nm] = dist[x][y][mask] + 1;
                        q.push({nx, ny, nm});
                    }
                } else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {
                    int id{grid[nx][ny] - 'A'};
                    if ((mask >> id) & 1 == 1) {
                        if (dist[nx][ny][mask] == -1) {
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.push({nx, ny, mask});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
