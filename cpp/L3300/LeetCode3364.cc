#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans{std::numeric_limits<int>::max()};
        int N = nums.size();
        for (int i = 0;i < N;++i) {
            int sum{0};
            for (int j{i};j < N && j - i + 1 <= r;++j) {
                sum += nums[j];
                if (j - i + 1 >= l && sum > 0) {
                    ans = std::min(ans, sum);
                }
            }
        }
        return ans == std::numeric_limits<int>::max() ? -1 : ans;
    }
};
