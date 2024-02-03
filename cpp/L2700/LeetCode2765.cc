#include <vector>
using std::vector;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int nz = nums.size();
        if (nz < 2) {
            return -1;
        }
        int maxLen{0};
        for (int i = 0;i < nz - 1;++i) {
            if (i + 1 >= nz || nums[i] - nums[i + 1] != -1) {
                continue;
            }
            int diff = nums[i + 1] - nums[i];
            int j = i + 1;
            while (j + 1 < nz && nums[j + 1] - nums[j] == 0 - diff) {
                ++j;
                diff = -diff;
            }
            maxLen = std::max(maxLen, j - i + 1);
            i = j - 1;
        }
        return maxLen == 0 ? -1 : maxLen;
    }
};