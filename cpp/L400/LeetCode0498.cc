#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        vector<int> res;
        int x = 0, y = 0;
        bool top = true;
        for (int i = 0;i < M * N;) {
            while (x >= 0 && x < M && y >= 0 && y < N) {
                res.push_back(mat[x][y]);
                if (top) {
                    x = x - 1;
                    y = y + 1;
                } else {
                    x = x + 1;
                    y = y - 1;
                }
                ++i;
            }
            if (top) {
                x = x + 1;
                y = y - 1;
                if (y + 1 < N) {
                    y = y + 1;
                } else {
                    x = x + 1;
                }
            } else {
                x = x - 1;
                y = y + 1;
                if (x + 1 < M) {
                    x = x + 1;
                } else {
                    y = y + 1;
                }
            }
            top = !top;
        }
        return res;
    }
};