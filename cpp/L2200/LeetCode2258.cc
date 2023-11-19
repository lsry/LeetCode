#include <array>
#include <queue>
#include <tuple>
#include <vector>
using std::vector;

class Solution {
    constexpr static std::array<std::array<int, 2>, 4> indics{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};

    std::tuple<int, int, int> bfs(vector<vector<int>> const &grid, vector<std::pair<int, int>> &pos) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> time(M, vector<int>(N, -1));
        std::queue<std::pair<int, int>> q;
        for (auto const &[a, b] : pos) {
            time[a][b] = 0;
            q.push({a, b});
        }
        for (int t = 1;!q.empty();++t) {
            int sz = q.size();
            for (int i = 0;i < sz;++i) {
                auto [a, b] = q.front();
                q.pop();
                for (std::array<int, 2> const &idx : indics) {
                    int nx{idx[0] + a}, ny{idx[1] + b};
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == 0 && time[nx][ny] < 0) {
                        time[nx][ny] = t;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return {time[M - 1][N - 1], time[M - 2][N - 1], time[M - 1][N - 2]};
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<std::pair<int, int>> p;
        p.push_back({0, 0});
        auto [ps, pt, pl] = bfs(grid, p);
        if (ps == -1) {
            return -1;
        }
        p.clear();
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 1) {
                    p.push_back({i, j});
                }
            }
        }
        auto [fs, ft, fl] = bfs(grid, p);
        if (fs == -1) {
            return 1'000'000'000;
        }
        int d = fs - ps;
        if (d < 0) {
            return -1;
        }
        if (pt != -1 && pt + d < ft || pl != -1 && pl + d < fl) {
            return d;
        }
        return d - 1;
    }
};