#include <vector>
using std::vector;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        std::size_t M{grid.size()}, N{grid[0].size()};
        vector<int> row(N, 0);
        for (std::size_t i{0};i < M;++i) {
            row[0] = row[0] + grid[i][0];
            for (std::size_t j{1};j < N;++j) {
                row[j] = std::max(row[j], row[j - 1]) + grid[i][j];
            }
        }
        return row[N - 1];
    }
};