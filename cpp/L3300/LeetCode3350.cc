#include <vector>
using std::vector;

class Solution {
    bool checkIncreasingSubarray(vector<int> const &dp, int k) {
        for (int i = 0;i < dp.size();++i) {
            if (dp[i] >= k && i - k >= 0 && dp[i - k] >= k) {
                return true;
            }
        }
        return false;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 0);
        for (int i = 0;i < N;++i) {
            if (i > 0 && nums[i - 1] < nums[i]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        int left{1}, right = nums.size();
        for (;left < right;) {
            int mid = left + (right - left) / 2;
            if (checkIncreasingSubarray(dp, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};