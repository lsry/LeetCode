#include <cstddef>
#include <vector>
using std::vector;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        std::size_t nz{nums.size()};
        for (std::size_t i{0};i < nz;++i) {
            if (nums[i] != 1) {
                continue;
            }
            std::size_t j{i};
            while (j + 1 < nz && nums[j + 1] != 1) {
                ++j;
            }
            if (j + 1 < nz && j - i < k) {
                return false;
            }
            i = j;
        }
        return true;
    }
};
