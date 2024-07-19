#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum{std::accumulate(nums.begin(), nums.end(), 0)};
        int neg = sum - target;
        if (neg < 0 || neg % 2 == 1) {
            return 0;
        }
        neg /= 2;
        vector<int> dp(neg + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int x{neg};x >= num;--x) {
                dp[x] += dp[x - num];
            }
        }
        return dp[neg];
    }
};