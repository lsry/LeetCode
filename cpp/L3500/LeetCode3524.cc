#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long int> ans(k, 0LL);
        vector<vector<long long int>> dp(2, vector<long long int>(k, 0));
        int curId{0};
        for (int num : nums) {
            std::fill(dp[1 - curId].begin(), dp[1 - curId].end(), 0);
            for (int i = 0;i < k;++i) {
                dp[1 - curId][1LL * i * num % k] += dp[curId][i];
            }
            dp[1 - curId][num % k]++;
            for (int i = 0;i < k;++i) {
                ans[i] += dp[1 - curId][i];
            }
            curId = 1 - curId;
        }
        return ans;
    }
};
