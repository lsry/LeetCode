#include <vector>
using std::vector;
#include <array>

class Solution {
    constexpr static std::array<std::array<int, 2>, 9> indics{{
        {0, 0}, {0, 1},{0, -1}, {-1, 0}, {-1, -1}, {-1, 1},{1, 0}, {1, 1}, {1, -1}}};
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        std::size_t N{grid.size()};
        vector<vector<int>> res(N - 2, vector<int>(N - 2, 0));
        for (std::size_t i{1};i < N - 1;++i) {
            for (std::size_t j{1};j < N - 1;++j) {
                int v{0};
                for (std::array<int, 2> const &index : indics) {
                    int in = i + index[0];
                    int jn = j + index[1];
                    v = std::max(v, grid[in][jn]);
                }
                res[i - 1][j - 1] = v;
            }
        }
        return res;
    }
};