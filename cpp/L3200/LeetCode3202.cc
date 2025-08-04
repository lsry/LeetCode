#include <vector>
using std::vector;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans{0};
        for (int num : nums) {
            int cur = num % k;
            for (int i = 0;i < k;++i) {
                dp[i][cur] = dp[cur][i] + 1;
                ans = std::max(ans, dp[i][cur]);
            }
        }      
        return ans;
    }
};