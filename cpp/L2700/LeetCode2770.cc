#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum{std::accumulate(nums.begin(), nums.end(), 0LL)};
        long long int left{0};
        int nz = nums.size();
        int ans{0};
        for (int i = 0;i < nz - 1;++i) {
            left += nums[i];
            sum -= nums[i];
            if (left >= sum) {
                ++ans;
            }
        }
        return ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> dp(N, -1);
        dp[0] = 0;
        for (int i = 1;i < N;++i) {
            for (int j = 0;j < i;++j) {
                if (dp[j] != -1 && nums[i] - nums[j] >= -target && nums[i] - nums[j] <= target) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[N - 1];
    }
};
