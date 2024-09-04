#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int countWays(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        int ans{0};
        if (0 < nums[0]) {
            ++ans;
        }
        if (N > nums[N - 1]) {
            ++ans;
        }
        int elected{0};
        for (int i = 0;i < N - 1;++i) {
            ++elected;
            if (elected < nums[i + 1] && elected > nums[i]) {
                ++ans;
            }
        }
        return ans;
    }
};