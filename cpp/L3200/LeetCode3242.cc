#include <array>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

class NeighborSum {
    vector<vector<int>> &nums;
    std::unordered_map<int, std::pair<int, int>> poses;
    constexpr static std::array<std::array<int, 2>, 4> adjaces{{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
    constexpr static std::array<std::array<int, 2>, 4> diagonals{{{-1, -1}, {-1, 1}, {1, 1}, {1, -1}}};

    int helperSum(int value, std::array<std::array<int, 2>, 4> const &indics) {
        auto const &[x, y] = poses[value];
        int ans{0};
        for (std::array<int, 2> const &idx : indics) {
            int nx = x + idx[0];
            int ny = y + idx[1];
            if (nx >= 0 && nx < nums.size() && ny >= 0 && ny < nums[0].size()) {
                ans += nums[nx][ny];
            }
        }
        return ans;
    }
public:
    NeighborSum(vector<vector<int>>& grid): nums(grid) {
        for (int i = 0;i < grid.size();++i) {
            for (int j = 0;j < grid[i].size();++j) {
                poses[grid[i][j]] = std::pair<int, int>(i, j);
            }
        }
    }
    
    int adjacentSum(int value) {
        return helperSum(value, adjaces);
    }
    
    int diagonalSum(int value) {
        return helperSum(value, diagonals);
    }
};