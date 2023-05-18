#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (std::size_t i{0}, j{nums.size() - 1};i < j;) {
            if (nums[i] * (-1) == nums[j]) {
                return nums[j];
            } else if (-1 * nums[i] > nums[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return -1;
    }
};