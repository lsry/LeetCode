#include <vector>
using std::vector;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        std::size_t sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        int minNum = nums[0], maxNum = nums[0];
        for (std::size_t i{0};i < sz;++i) {
            minNum = std::min(minNum, nums[i]);
            maxNum = std::max(maxNum, nums[i]);
        }
        return maxNum - minNum <= 2 * k ? 0 : (maxNum - minNum - 2 * k);
    }
};