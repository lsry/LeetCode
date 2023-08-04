#include <vector>
using std::vector;
#include <array>

class Solution {
    constexpr static std::array<std::array<int, 3>, 4> indics{{{-1, 0, 1}, {0, 1, 2}, {1, 0, 3}, {0, -1, 4}}};
    int M, N;
    int ans{0};
    int start{0}, end{0}, count{0};
    void dfs(vector<vector<int>>& grid, int point, vector<bool> &flags, int curCount) {
        if (point == end) {
            if (curCount == count) {
                ++ans;
            }
            return;
        }
        int x = point / N;
        int y = point % N;
        if (grid[x][y] == -1) {
            return;
        }
        for (std::array<int, 3> const &index : indics) {
            int nx{x + index[0]}, ny{y + index[1]};
            int np{nx * N + ny};
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !flags[np]) {
                flags[np] = true;
                dfs(grid, np, flags, curCount + 1);
                flags[np] = false;
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        M = grid.size();
        if (M == 0) {
            return 0;
        }
        N = grid[0].size();
        if (N == 0) {
            return 0;
        }
        vector<bool> flags(M * N, false);
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] != -1) {
                    ++count;
                }
                if (grid[i][j] == 1) {
                    start = i * N + j;
                } else if (grid[i][j] == 2) {
                    end = i * N + j;
                } else if (grid[i][j] == -1) {
                    flags[i * N + j] = true;
                }
            }
        }
        flags[start] = true;
        dfs(grid, start, flags, 1);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> g{{1,2}, {0, 0}};
    s.uniquePathsIII(g);
    return 0;
}
