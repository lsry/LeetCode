#include <vector>
using std::vector;

#include <limits>
#include <array>

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        std::size_t m = matrix.size(), n = matrix[0].size();
        vector<int> row(m, std::numeric_limits<int>::max());
        vector<int> col(n, std::numeric_limits<int>::min());
        for (std::size_t i = 0;i < m;++i) {
            for (std::size_t j = 0;j < n;++j) {
                row[i] = std::min(row[i], matrix[i][j]);
                col[j] = std::max(col[j], matrix[i][j]);
            }
        }
        vector<int> res;
        for (std::size_t i = 0;i < m;++i) {
            for (std::size_t j = 0;j < n;++j) {
                if (matrix[i][j] == row[i] && matrix[i][j] == col[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};