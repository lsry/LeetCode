#include <vector>
using std::vector;
#include <limits>

class Solution {
    int N;
    int productSum(vector<int> const &arr, int low, int high, vector<vector<int>> &dp) {
        int range{high - low + 1};
        if (range < 2) {
            return 0;
        }
        if (dp[low][high] != -1) {
            return dp[low][high];
        }
        int sum{std::numeric_limits<int>::max()};
        int left_max{0};
        vector<int> rmaxs(range, 0);
        rmaxs[range - 1] = arr[high];
        for (int x = range - 2;x >= 0;--x) {
            rmaxs[x] = std::max(rmaxs[x + 1], arr[high + x - range + 1]);
        }
        for (int x = low;x < high;++x) {
            left_max = std::max(left_max, arr[x]);
            int curSum = left_max * rmaxs[x - low + 1];
            curSum += productSum(arr, low, x, dp);
            curSum += productSum(arr, x + 1, high, dp);
            sum = std::min(sum, curSum);
        }
        dp[low][high] = sum;
        return sum;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        N = arr.size();
        if (N < 2) {
            return 0;
        } 
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return productSum(arr, 0, N - 1, dp);
    }
};