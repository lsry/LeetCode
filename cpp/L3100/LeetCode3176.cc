#include <vector>
using std::vector;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int N = nums.size();
        if (N < 2) {
            return N;
        }
        vector<vector<int>> dp(N, vector<int>(k + 1, 0));
        int ans{1};
        for (int i = 0;i < N;++i) {
            dp[i][0] = 1;
            for (int j = i - 1;j >= 0;--j) {
                if (nums[j] == nums[i]) {
                    dp[i][0] = std::max(dp[i][0], dp[j][0] + 1);
                }
                for (int x = 1;x <= k;++x) {
                    if (nums[i] == nums[j]) {
                        dp[i][x] = std::max(dp[i][x], dp[j][x] + 1);
                    } else {
                        dp[i][x] = std::max(dp[i][x], dp[j][x - 1] + 1);
                    }
                }
            }
            for (int x = 0;x <= k;++x) {
                ans = std::max(ans, dp[i][x]);
            }
        }
        return ans;
    }
};