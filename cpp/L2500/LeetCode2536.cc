#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n + 1, 0));
        for (vector<int> const &query : queries) {
            for (int r{query[0]};r <= query[2];++r) {
                mat[r][query[1]] += 1;
                mat[r][query[3] + 1] -= 1;
            }
        }
        for (int i = 0;i < n;++i) {
            for (int j = 1;j < n;++j) {
                mat[i][j] = mat[i][j] + mat[i][j - 1];
            }
            mat[i].pop_back();
        }
        return mat;
    }
};
