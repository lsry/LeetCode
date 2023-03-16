#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int R = rowSum.size(), C = colSum.size();
        vector<vector<int>> res(R, vector<int>(C, 0));
        std::copy(colSum.begin(), colSum.end(), res[R - 1].begin());
        for (int i = 0;i < R - 1;++i) {
            int ri = rowSum[i];
            for (int j = 0;j < C;++j) {
                res[i][j] = std::min(ri, res[R - 1][j]);
                ri -= res[i][j];
                res[R - 1][j] -= res[i][j];
            }
        }
        return res;
    }
};