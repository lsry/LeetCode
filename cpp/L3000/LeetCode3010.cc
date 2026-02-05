#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        std::sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};
