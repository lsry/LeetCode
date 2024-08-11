#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        int ans = std::numeric_limits<int>::max();
        for (int i = 0;i < N - 1;++i) {
            ans = std::min(ans, nums[i + 1] - nums[i]);
        }
        return ans;
    }
};