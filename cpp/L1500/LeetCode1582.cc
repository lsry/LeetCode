#include <vector>
using std::vector;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        vector<int> row(M, 0), col(N, 0);
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (mat[i][j] == 1) {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        int ans{0};
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
