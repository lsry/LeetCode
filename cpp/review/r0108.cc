#include <vector>
using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        vector<int> rows, cols;
        std::size_t M{matrix.size()}, N{matrix[0].size()};
        for (std::size_t i{0};i < M;++i) {
            for (std::size_t j{0};j < N;++j) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for (int row : rows) {
            std::fill(matrix[row].begin(), matrix[row].end(), 0);
        }
        for (int col : cols) {
            for (std::size_t i{0};i < M;++i) {
                matrix[i][col] = 0;
            }
        }
    }
};