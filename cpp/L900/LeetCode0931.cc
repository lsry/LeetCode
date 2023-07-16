#include <vector>
using std::vector;
#include <limits>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<int> v1(N, 0), v2(N, std::numeric_limits<int>::max());
        vector<int> &v1t = v1, &v2t = v2;
        for (int i{0};i < M;++i) {
            std::fill(v2t.begin(), v2t.end(), std::numeric_limits<int>::max());
            for (int j{0};j < N;++j) {
                if (j > 0) {
                    v2t[j] = std::min(v2t[j], matrix[i][j] + v1t[j - 1]);
                }
                v2t[j] = std::min(v2t[j], matrix[i][j] + v1t[j]);
                if (j < N - 1) {
                    v2t[j] = std::min(v2t[j], matrix[i][j] + v1t[j + 1]);
                }
            }
            vector<int> &vt = v1t;
            v1t = v2t;
            v2t = vt;
        }
        return *min_element(v1t.begin(), v1t.end());
    }
};