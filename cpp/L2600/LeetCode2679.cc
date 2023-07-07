#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (vector<int> &row : nums) {
            std::sort(row.begin(), row.end());
        }
        int goal{0};
        for (int c = nums[0].size() - 1;c >= 0;--c) {
            int mx{0};
            for (int r = 0;r < nums.size();++r) {
                mx = std::max(mx, nums[r][c]);
            }
            goal += mx;
        }
        return goal;
    }
};