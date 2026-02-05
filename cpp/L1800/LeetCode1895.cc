#include <vector>
using std::vector;

class Solution {
    int M, N;

    bool checkSquare(vector<vector<int>> const &grid, int x, int y, int len) {
        if (x + len > M || y + len > N) {
            return false;
        }
        int sum{0};
        for (int i = 0;i < len;++i) {
            sum += grid[x + i][y];
        }
        int mainSum{0}, sideSum{0};
        for (int i = 0;i < len;++i) {
            int xSum{0}, ySum{0};
            for (int j = 0;j < len;++j) {
                xSum += grid[x + i][y + j];
                ySum += grid[x + j][y + i];
            }
            if (xSum != sum || ySum != sum) {
                return false;
            }
            mainSum += grid[x + i][y + i];
            sideSum += grid[x + i][y + len - 1 - i];
        }
        return mainSum == sum && sideSum == sum;
    }

    int getMaxLen(vector<vector<int>> const &grid, int x, int y) {
        int len{1};
        for (int i = std::min(M, N);i > 1;--i) {
            if (checkSquare(grid, x, y, i)) {
                len = i;
                break;
            }
        }
        return len;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();
        int len = 0;
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                len = std::max(len, getMaxLen(grid, i, j));
            }
        }
        return len;
    }
};
