#include <vector>
using std::vector;

#include <array>
using std::array;

#include <algorithm>

#include <queue>
using std::queue;

#include <tuple>
using std::pair;

class Solution {
private:
    std::size_t M, N;
    constexpr static array<array<int, 2>, 4> indics{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    int bfs(int fx, int fy, int ex, int ey, vector<vector<int>>& forest) {
        if (fx == ex && fy == ey) {
            return 0;
        }
        vector<vector<bool>> vis(M, vector<bool>(N));
        queue<pair<int, int>> qu;
        qu.push({fx, fy});
        int dis = 0;
        while (!qu.empty()) {
            std::size_t qz{qu.size()};
            for (std::size_t i{0};i < qz;++i) {
                auto [cx, cy] = qu.front();
                qu.pop();
                if (cx == ex && cy == ey) {
                    return dis;
                }
                vis[cx][cy] = true;
                for (array<int, 2> const &idx : indics) {
                    int nx = cx + idx[0];
                    int ny = cy + idx[1];
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && !vis[nx][ny] && forest[nx][ny] > 0) {
                        vis[nx][ny] = true;
                        qu.push({nx, ny});
                    }
                }
            }
            dis++;
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest[0][0] == 0) {
            return -1;
        }
        M = forest.size();
        N = forest[0].size();
        vector<array<int, 3>> wait;
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (forest[i][j] > 1) {
                    wait.push_back({i, j, forest[i][j]});
                }
            }
        }
        std::stable_sort(wait.begin(), wait.end(), [](array<int, 3> const &a1, array<int, 3> const &a2) {
            return a1[2] < a2[2];
        });
        int fi = 0, fj = 0;
        int ans = 0;
        for (array<int, 3> &arr : wait) {
            int dis = bfs(fi, fj, arr[0], arr[1], forest);
            if (dis == -1) {
                return -1;
            }
            ans += dis;
            fi = arr[0];
            fj = arr[1];
        }
        return ans;
    }
};