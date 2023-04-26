#include <vector>
using std::vector;

class Solution {
    int trace(vector<int>& arr, int k, int low, int high, vector<vector<int>> &dp) {
        if (low > high) {
            return 0;
        }
        if (dp[low][high] != -1) {
            return dp[low][high];
        }
        if (high - low + 1 <= k) {
            int maxValue{0};
            for (int i = low;i <= high;++i) {
                maxValue = std::max(maxValue, arr[i]);
            }
            dp[low][high] = maxValue * (high - low + 1);
            return dp[low][high];
        }
        int maxValue{0};
        for (int i = low;i - low + 1 <= k;++i) {
            maxValue = std::max(maxValue, arr[i]);
            dp[low][high] = std::max(dp[low][high], maxValue * (i - low + 1) + trace(arr, k, i + 1, high, dp));
        }
        return dp[low][high];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return trace(arr, k, 0, n - 1, dp);
    }
};