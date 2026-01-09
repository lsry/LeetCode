#include <vector>
using std::vector;

class Solution {
public:
    int repeatedNTimesN(vector<int>& nums) {
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

    int repeatedNTimes(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        int count{0}, n{-1};
        std::size_t nz{nums.size()};
        for (int i = 1;i < nz;++i) {
            if (nums[i] == nums[0]) {
                return nums[0];
            }
            if (count == 0) {
                n = nums[i];
                count = 1;
            } else if (n != nums[i]) {
                --count;
            } else {
                ++count;
            }
        }
        return n;
    }
};
