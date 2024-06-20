#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    int tripple(vector<int> const &nums, vector<vector<int>> &dp, int goal, int left, int right) {
        if (right - left + 1 < 2) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        dp[left][right] = 0;
        if (nums[left] + nums[left + 1] == goal) {
            dp[left][right] = std::max(dp[left][right], tripple(nums, dp, goal, left + 2, right) + 1);
        }
        if (nums[left] + nums[right] == goal) {
            dp[left][right] = std::max(dp[left][right], tripple(nums, dp, goal, left + 1, right - 1) + 1);
        }
        if (nums[right] + nums[right - 1] == goal) {
            dp[left][right] = std::max(dp[left][right], tripple(nums, dp, goal, left, right - 2) + 1);
        }
        return dp[left][right];
    }
public:
    int maxOperations(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) {
            return 0;
        }
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int ans{0};
        ans = std::max(ans, tripple(nums, dp, nums[0] + nums[1], 2, N - 1) + 1);
        for (vector<int> &d : dp) {
            std::fill(d.begin(), d.end(), -1);
        }
        ans = std::max(ans, tripple(nums, dp, nums[0] + nums[N - 1], 1, N - 2) + 1);
        for (vector<int> &d : dp) {
            std::fill(d.begin(), d.end(), -1);
        }
        ans = std::max(ans, tripple(nums, dp, nums[N - 1] + nums[N - 2], 0, N - 3) + 1);
        return ans;
    }
};

int main() {
    vector<int> v{3,1,9,3,6,6,3,2,4};
    Solution s;
    s.maxOperations(v);
}