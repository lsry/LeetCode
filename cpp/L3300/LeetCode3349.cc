#include <vector>
using std::vector;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> dp(N, 0);
        for (int i = 0;i < N;++i) {
            if (i > 0 && nums[i - 1] < nums[i]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        for (int i = 0;i < N;++i) {
            if (dp[i] >= k && i - k >= 0 && dp[i - k] >= k) {
                return true;
            }
        }
        return false;
    }
};