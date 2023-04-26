#include <vector>
using std::vector;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int nz = nums.size();
        vector<vector<int>> dp(501, vector<int>(1002, 0));
        int len{0};
        for (int n : nums) {
            dp[n][0] += 1;
            len = std::max(dp[n][0], len);
            for (int d = -500;d <= 500;++d) {
                if (d != 0 && n + d >= 0 && n + d <= 500 && dp[n + d][0] > 0) {
                    dp[n][d + 500] = dp[n + d][d + 500] == 0 ? 2 : dp[n + d][d + 500] + 1;
                    len = std::max(len, dp[n][d + 500]);
                }
            }
        }
        return len;
    }
};