#include <vector>
using std::vector;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd{0}, even{0};
        std::size_t nz{nums.size()};
        for (std::size_t i{0};i < nz;++i) {
            if (i % 2 == 0) {
                even += nums[i];
            } else {
                odd += nums[i];
            }
        }
        int lastOdd{0}, lastEven{0};
        int ans{0};
        for (std::size_t i{0};i < nz;++i) {
            if (i % 2 == 0) {
                even -= nums[i];
            } else {
                odd -= nums[i];
            }
            if (lastOdd + even == lastEven + odd) {
                ++ans;
            }
            i % 2 == 0 ? lastEven += nums[i] : lastOdd += nums[i];
        }
        return ans;
    }
};