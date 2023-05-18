#include <vector>
using std::vector;
#include <deque>
#include <algorithm>
#include <array>
#include <limits>

class Solution {
    constexpr static std::array<std::array<int, 4>, 4> dirs{{{0, -1, 0, 1}, {0, 1, 0, -1}, {1, 0, -1, 0}, {-1, 0, 1, 0}}};
    int M, N;
public:
    int minPushBox(vector<vector<char>>& grid) {
        int bx{0}, by{0}, sx{0}, sy{0}, tx{0}, ty{0};
        M = grid.size(), N = grid[0].size();
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 'B') {
                    bx = i;
                    by = j;
                } else if (grid[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (grid[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }
            }
        }
        std::deque<vector<int>> q;
        q.emplace_back(vector<int>{bx, by, sx, sy, 0});
        vector<vector<vector<vector<bool>>>> visited(M, vector<vector<vector<bool>>>(N, vector<vector<bool>>(M, vector<bool>(N, false))));
        visited[bx][by][sx][sy] = 0;
        while (!q.empty()) {
            vector<int> pos{q.front()};
            q.pop_front();
            if (pos[0] == tx && pos[1] == ty) {
                return pos[4];
            }
            for (std::array<int, 4> const &dir : dirs) {
                int nsx{pos[2] + dir[0]}, nsy{pos[3] + dir[1]};
                if (nsx < 0 || nsx >= M || nsy < 0 || nsy >= N || grid[nsx][nsy] == '#') {
                    continue;
                }
                if (nsx == pos[0] && nsy == pos[1]) {
                    int nbx{pos[0] + dir[0]}, nby{pos[1] + dir[1]};
                    if (nbx >= 0 && nbx < M && nby >= 0 && nby < N && grid[nbx][nby] != '#' 
                        && !visited[nbx][nby][nsx][nsy]) {
                        q.emplace_back(vector<int>{nbx, nby, nsx, nsy, pos[4] + 1});
                        visited[nbx][nby][nsx][nsy] = true;
                    }
                } else if (!visited[pos[0]][pos[1]][nsx][nsy]) {
                    q.emplace_front(vector<int>{pos[0], pos[1], nsx, nsy, pos[4]});
                    visited[pos[0]][pos[1]][nsx][nsy] = true;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> grid{{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},{'#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#'},{'#','.','#','#','#','#','.','#','#','#','#','.','#','#','#','.'},{'#','.','.','.','.','.','.','#','T','#','.','.','#','#','#','.'},{'#','.','.','.','#','.','.','.','.','.','.','.','#','#','#','.'},{'#','.','.','.','.','.','B','.','.','.','.','.','#','#','#','.'},{'#','.','#','#','#','#','#','#','#','#','#','.','#','#','#','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','S','.','.','.','.','.','.','.'},{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
    int x =  s.minPushBox(grid);
    return 0;
}
