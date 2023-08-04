#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (vector<int> &g : grid) {
            std::stable_sort(g.begin(), g.end(), [](int a, int b){
                return a > b;
            });
        }
        int ans{0};
        for (int col{0};col < grid[0].size();++col) {
            int v{grid[0][col]};
            for (int row{0};row < grid.size();row) {
                v = std::max(grid[row][col], v);
            }
            ans += v;
        }
        return ans;
    }
};