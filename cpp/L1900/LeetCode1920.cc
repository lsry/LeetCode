#include <cstddef>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        std::size_t nz{nums.size()};
        for (std::size_t i{0};i < nz;++i) {
            int cur = nums[nums[i] % 1000] % 1000;
            nums[i] = cur * 1000 + nums[i];
        }
        for (std::size_t i{0};i <nz;++i) {
            nums[i] = nums[i] / 1000;
        }
        return nums;
    }
};