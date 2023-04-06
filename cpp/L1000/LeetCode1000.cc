#include <vector>
using std::vector;

class Solution {
    int sz;
    int K;
    int dfs(int low, int high, int k, vector<vector<vector<int>>> &dp, vector<int> &sums) {
        if (low > high || high - low + 1 < k) {
            return -1;
        } 
        if (dp[low][high][k] != -2) {
            return dp[low][high][k];
        } 
        if (high - low + 1 == k) {
            return 0;
        }
        if (k == 1) {
            int sum = dfs(low, high, K, dp, sums);
            if (sum == -1) {
                return -1;
            }
            sum += sums[high] - sums[low - 1];
            dp[low][high][k] = sum;
            return dp[low][high][k];
        }
        dp[low][high][k] = -1;
        for (int m = low;m < high;++m) {
            int x1 = dfs(low, m, 1, dp, sums);
            if (x1 == -1) {
                continue;
            }
            int x2 = dfs(m + 1, high, k - 1, dp, sums);
            if (x2 == -1) {
                continue;
            }
            dp[low][high][k] = dp[low][high][k] == -1 ? x1 + x2 : std::min(dp[low][high][k], x1 + x2);
        }
        return dp[low][high][k];
    }
public:
    int mergeStones(vector<int>& stones, int k) {
        sz = stones.size();
        K = k;
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(sz + 1, vector<int>(k + 1, -2)));
        vector<int> sums(sz + 1, 0);
        for (int i = 0;i < sz;++i) {
            sums[i + 1] = sums[i] + stones[i];
        }
        return dfs(1, sz, 1, dp, sums);
    }
};