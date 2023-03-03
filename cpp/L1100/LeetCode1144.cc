#include <vector>
using std::vector;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int even{0}, odd{0};
        int nz = nums.size();
        if (nz < 2) {
            return 0;
        }
        for (int i = 0;i < nz;i += 2) {
            if (i == 0) {
                if (nums[i] >= nums[i + 1]) {
                    even += nums[i] - nums[i + 1] + 1;
                }
            } else if (i == nz - 1) {
                if (nums[i] >= nums[i - 1]) {
                    even += nums[i] - nums[i - 1] + 1;
                }
            } else {
                int n = std::min(nums[i - 1], nums[i + 1]);
                if (nums[i] >= n) {
                    even += nums[i] - n + 1;
                }
            }
        }
        for (int i = 1;i < nz;i += 2) {
            if (i == nz - 1) {
                if (nums[i] >= nums[i - 1]) {
                    odd += nums[i] - nums[i - 1] + 1;
                }
            } else {
                int n = std::min(nums[i - 1], nums[i + 1]);
                if (nums[i] >= n) {
                    odd += nums[i] - n + 1;
                }
            }
        }
        return std::min(odd, even);
    }
};