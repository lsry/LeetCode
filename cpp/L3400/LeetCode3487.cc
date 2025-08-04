#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        if (nums[N - 1] <= 0) {
            return nums[N - 1];
        }
        int ans{0};
        for (int i = N - 1;i >= 0 && nums[i] > 0;) {
            ans += nums[i];
            int j{i};
            while (j >= 0 && nums[j] == nums[i]) {
                --j;
            }
            i = j;
        }
        return ans;
    }
};