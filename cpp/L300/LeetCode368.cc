#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());  
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(2, -1));
        int maxLen{0};
        for (int i = 0;i < N;++i) {
            dp[i][0] = 1;
            for (int j = i - 1;j >= 0;--j) {
                if (nums[i] % nums[j] == 0 && dp[j][0] + 1 > dp[i][0]) {
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = j;
                }
            }
            maxLen = std::max(maxLen, dp[i][0]);
        }
        vector<int> ans;
        for (int i = N - 1;i >= 0;--i) {
            if (maxLen != dp[i][0]) {
                continue;
            }
            int j = i;
            while (j >= 0) {
                ans.push_back(nums[j]);
                j = dp[j][1];
            }
            break;
        }
        return ans;
    }
};