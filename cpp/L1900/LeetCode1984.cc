#include <vector>
using std::vector;

#include <limits>
#include <algorithm>

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int diff = std::numeric_limits<int>::max();
        int sz = nums.size();
        for (int i = 0;i + k - 1 < sz;++i) {
            diff = std::min(nums[i + k - 1] - nums[i], diff);
        }
        return diff;
    }
};