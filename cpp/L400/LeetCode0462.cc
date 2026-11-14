#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    /***
     * middle position num
     */
    int minMoves2(vector<int>& nums) {
        std::stable_sort(nums.begin(), nums.end());
        std::size_t nz{nums.size()};
        int rm = nz / 2;
        int count = 0;
        for (int num : nums) {
            count += num > nums[rm] ? num - nums[rm] : nums[rm] - num;
        }
        return count;
    }
};
