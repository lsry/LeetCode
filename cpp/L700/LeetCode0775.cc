#include <vector>
using std::vector;

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        std::size_t nz{nums.size()};
        int previous_max{-1};
        for (std::size_t i{1};i < nz;++i) {
            if (previous_max > nums[i]) {
                return false;
            }
            previous_max = std::max(previous_max, nums[i - 1]);
        }
        return true;
    }
};