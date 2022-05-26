#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        std::size_t nz{nums.size()};
        for (std::size_t i{0};i < nz;++i) {
            for (std::size_t j{1};j <= 3;++j) {
                if (i + j < nz && nums[i] == nums[i + j]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};