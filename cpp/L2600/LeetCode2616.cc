#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int N = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<int> dp(N + 1, 0);
        int low{0}, high{nums[N - 1] - nums[0]};
        while (low < high) {
            int mid = low + (high - low) / 2;
            std::fill(dp.begin(), dp.end(), 0);
            for (int i = 2;i <= N;++i) {
                dp[i] = std::max(dp[i - 1], dp[i - 2] + (nums[i - 1] - nums[i - 2] <= mid));
            }
            if (dp[N] >= p) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }      
        return low;
    }
};