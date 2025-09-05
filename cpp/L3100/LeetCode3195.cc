#include <vector>
using std::vector;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        int rl = M, rr = -1;
        int cl = N, cr = -1;
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 1) {
                    rl = std::min(rl, i);
                    rr = std::max(rr, i);
                    cl = std::min(cl, j);
                    cr = std::max(cr, j);
                }
            }
        }      
        if (rl >rr || cl > cr) {
            return 0;
        }
        return (rr - rl + 1) * (cr - cl + 1);
    }
};