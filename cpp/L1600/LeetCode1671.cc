#include <vector>
using std::vector;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> dp(2, vector<int>(sz, 1));
        for (int i = 1;i < sz;++i) {
            for (int j = i - 1;j >= 0;--j) {
                if (nums[j] < nums[i] && dp[0][j] + 1 > dp[0][i]) {
                    dp[0][i] = dp[0][j] + 1;
                }
            }
        }
        for (int i = sz - 2;i >= 0;--i) {
            for (int j = i + 1;j < sz;++j) {
                if (nums[j] < nums[i] && dp[1][j] + 1 > dp[1][i]) {
                    dp[1][i] = dp[1][j] + 1;
                }
            }
        }
        int ans{sz};
        for (int i = 1;i < sz - 1;++i) {
            int x = dp[0][i] + dp[1][i] - 1;
            if (x >= 3 && dp[0][i] >= 2 && dp[1][i] >= 2) {
                ans = std::min(ans, sz - x);
            }
        }
        return ans;
    }
};