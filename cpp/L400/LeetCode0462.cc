#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::stable_sort(nums.begin(), nums.end());
        std::size_t nz{nums.size()};
        int rm = nz / 2;
        int lm{rm};
        if (nz % 2 == 0 && nz > 1) {
            lm = rm - 1;
        }
        int count1 = 0, count2 = 0;
        for (int num : nums) {
            count1 += num > nums[lm] ? num - nums[lm] : nums[lm] - num;
            count2 += num > nums[rm] ? num - nums[rm] : nums[rm] - num;
        }
        return std::min(count1, count2);
    }
};