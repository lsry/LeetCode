#include <vector>
using std::vector;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for (int i = 0;i < N / 2;++i) {
            for (int r = i, c = 0;c < (N + 1) / 2;++c) {
                int t = matrix[N - c - 1][r];
                matrix[N - c - 1][r] = matrix[N - r - 1][N - c - 1];
                matrix[N - r - 1][N - c - 1] = matrix[c][N - r - 1];
                matrix[c][N - r - 1] = matrix[r][c];
                matrix[r][c] = t;
            }
        }
    }
};
