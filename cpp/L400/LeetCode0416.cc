#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum{std::accumulate(nums.begin(), nums.end(), 0)};
        if (sum % 2 != 0) {
            return false;
        }
        int half = sum / 2;
        vector<bool> dp(half + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = half;i >= num;--i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[half];
    }
};