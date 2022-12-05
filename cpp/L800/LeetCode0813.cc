#include <vector>
using std::vector;

#include <algorithm>
#include <numeric>

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int nz = nums.size();
        vector<vector<double>> dp(nz + 1, vector<double>(k + 1, 0.0));
        vector<double> sums(nz + 1, 0.0);
        for (int i = 1;i <= nz;++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1;i <= nz;++i) {
            dp[i][1] = sums[i] / i;
        }
        for (int t = 2;t <= k;++t) {
            for (int i = t;i <= nz;++i) {
                for (int x = t - 1;x < i;++x) {
                    dp[i][t] = std::max(dp[i][t], dp[x][t - 1] + (i - x == 0 ? 0.0 : (sums[i] - sums[x]) / (i - x)));
                }
            }
        }
        return dp[nz][k];
    }
};