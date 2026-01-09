#include <vector>
using std::vector;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        int ans{0};
        for (int i = 0, j = N - 1;i < M && j >= 0;) {
            while (i < M && grid[i][j] >= 0) {
                ++i;
            }
            if (i >= M) {
                break;
            }
            ans += M - i;
            --j;
        }
        return ans;
    }
};
