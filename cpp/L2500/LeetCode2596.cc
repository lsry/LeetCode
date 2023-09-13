#include <array>
#include <vector>
using std::vector;

class Solution {
    constexpr static std::array<std::array<int, 2>, 8> indics{{{-1,-2}, {-2,-1}, {-2,1}, {-1, 2}, {1,-2}, {2,-1}, {1,2}, {2,1}}};
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int N = grid.size();
        int x{0}, y{0};
        for (int i = 0;i < N * N;++i) {
            if (grid[x][y] != i) {
                return false;
            }
            for (std::array<int, 2> const &index : indics) {
                int nx{x + index[0]}, ny{y + index[1]};
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] == i + 1) {
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }
        return true;
    }
};