#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
private:
    std::size_t N{0};
    int perSum{0};
    int dfs(vector<int> &nums, vector<int> &dp, int curSum, int state) {
        if (state == 0) {
            return 1;
        }
        if (dp[state] != 0) {
            return dp[state];
        }
        dp[state] = -1;
        for (std::size_t i{0};i < N;++i) {
            if (curSum + nums[i] > perSum) {
                break;
            }
            if (((state >> i) & 1) == 1) {
                int r = dfs(nums, dp, (curSum + nums[i]) % perSum, state & (~(1 << i)));
                if (r == 1) {
                    dp[state] = r;
                    break;
                }
            }   
        }
        return dp[state];
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (k == 0 || sum % k != 0) {
            return false;
        }
        if (k == 1) {
            return true;
        }
        perSum = sum / k;
        N = nums.size();
        std::stable_sort(nums.begin(), nums.end());
        vector<int> dp(1 << N, 0);
        return dfs(nums, dp, 0, (1 << N) - 1) == 1;
    }
};