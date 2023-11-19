#include <vector>
using std::vector;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int nz = nums.size();
        int ans{0};
        for (int i = 0;i < nz;++i) {
            if (nums[i] % 2 == 1 || nums[i] > threshold) {
                continue;
            }
            int j{i + 1};
            for (;j < nz && nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2;++j);
            ans = std::max(ans, j - i);
        }
        return ans;
    }
};