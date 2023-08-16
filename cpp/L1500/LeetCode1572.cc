#include <vector>
using std::vector;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans{0};
        int N = mat.size();
        for (int i = 0;i < N;++i) {
            ans += mat[i][i];
        }
        for (int r{0}, c{N - 1};r < N && c >= 0;++r, --c) {
            if (r != c) {
                ans += mat[r][c];
            }
        }
        return ans;
    }
};