#include <numeric>
#include <vector>
using std::vector;

class Solution {
    int trace(vector<int> const &nums, int f, int e, vector<vector<int>> &dp, int selected) {
        if (f > e) {
            return 0;
        }
        int x1 = trace(nums, f + 1, e, dp, selected * -1) + nums[f] * selected;
        int x2 = trace(nums, f, e - 1, dp, selected * -1) + nums[e] * selected;
        dp[f][e] = std::max(x1 * selected, x2 * selected);
        return dp[f][e] * selected;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int goal = trace(nums, 0, N - 1, dp, 1);
        return goal >= 0;
    }
};
