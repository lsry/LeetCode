#include <vector>
using std::vector;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int N = grid.size();
        int ans = N * N;
        for (int i{0};i < N;++i) {
            int row = 0, col = 0;
            for (int j{0};j < N;++j) {
                row = std::max(row, grid[i][j]);
                col = std::max(col, grid[j][i]);
                if (grid[i][j] == 0) {
                    ans -= 1;
                }
            }
            ans += row + col;
        }
        return ans;
    }
};