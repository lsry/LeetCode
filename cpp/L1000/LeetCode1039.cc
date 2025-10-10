#include <vector>
using std::vector;
#include <limits>

class Solution {
    int N;
    int trace(vector<int> const &datas, int low, int high, vector<vector<int>> &dp) {
        if (high == low + 1) {
            return 0;
        }
        if (dp[low][high] != -1) {
            return dp[low][high];
        }
        int ans{std::numeric_limits<int>::max()};
        for (int k = low + 1;k < high;++k) {
            ans = std::min(ans, datas[low] * datas[k] * datas[high] + trace(datas, low, k, dp) + trace(datas, k, high, dp));
        }
        dp[low][high] = ans;
        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        N = values.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        trace(values, 0, N - 1, dp);
        return dp[0][N - 1];
    }
};