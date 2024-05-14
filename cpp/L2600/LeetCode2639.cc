#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<int> ans(C, 0);
        for (int i = 0;i < C;++i) {
            int len{0};
            for (int j = 0;j < R;++j) {
                int cur = 1;
                int num = grid[j][i];
                if (num < 0) {
                    cur = 2;
                    num = -num;
                }
                while (num > 9) {
                    ++cur;
                    num = num / 10;
                }
                len = std::max(len, cur);
            }
            ans[i] = len;
        }
        return ans;
    }
};