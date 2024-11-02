#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        int ans{nums[N - 1] - nums[0]};
        for (int i = 1;i < N;++i) {
            int mx = std::max(nums[i - 1] + k, nums[N - 1] - k);
            int ms = std::min(nums[0] + k, nums[i] - k);
            ans = std::min(ans, mx - ms);
        }
        return ans;
    }
};