#include <vector>
using std::vector;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<int> rows(R, 0), cols(C, 0);
        for (int i = 0;i < R;++i) {
            for (int j = 0;j < C;++j) {
                if (grid[i][j] == 1) {
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }
        long long ans{0LL};
        for (int i = 0;i < R;++i) {
            for (int j = 0;j < C;++j) {
                if (grid[i][j] == 1) {
                    int r = rows[i] - 1;
                    int c = cols[j] - 1;
                    ans += 1LL * r * c;
                }
            }
        }
        return ans;
    }
};