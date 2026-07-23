#include <vector>
using std::vector;

class Solution {
    void reverseErwei(vector<vector<int>> &grid, int start, int end) {
        int N = grid[0].size();
        while (start < end) {
            int sx = start / N, sy = start % N;
            int ex = end / N, ey = end % N;
            int temp = grid[sx][sy];
            grid[sx][sy] = grid[ex][ey];
            grid[ex][ey] = temp;
            ++start;
            --end;
        }
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int M = grid.size(), N = grid[0].size();
        int LN = M * N;
        k = k % LN;
        reverseErwei(grid, 0, LN - 1);
        reverseErwei(grid, k, LN - 1);
        reverseErwei(grid, 0, k - 1);
        return grid;
    }
    // open new array
    vector<vector<int>> shiftGridNewArray(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        k = k % (m * n);
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                int id = (i * n + j + k) % (m * n);
                res[id / n][id % n] = grid[i][j];
            }
        }
        return res;
    }
};
