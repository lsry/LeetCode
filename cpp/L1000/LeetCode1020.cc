#include <vector>
using std::vector;

#include <array>
using std::array;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();
        for (int i = 0;i < M;++i) {
            dfs(grid, i, 0);
            dfs(grid, i, N - 1);
        }
        for (int i = 0;i < N;++i) {
            dfs(grid, 0, i);
            dfs(grid, M - 1, i);
        }
        int count = 0;
        for (vector<int> &vi : grid) {
            for (int &i : vi) {
                if (i == 1) {
                    ++count;
                }
            }
        }
        return count;
    }
private:
    int M{0}, N{0};
    const array<array<int, 2>, 4> indics{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    void dfs(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || grid[x][y] != 1) {
            return;
        }
        grid[x][y] = 2;
        for (array<int, 2> index : indics) {
            int nx = x + index[0], ny = y + index[1];
            dfs(grid, nx, ny);
        }
        return;
    }
};