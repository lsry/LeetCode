#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int N = nums.size();
        std::sort(nums.begin(), nums.end());
        int ans{0};
        for (int i = 0,j = 0;j < N;++i) {
            int v = nums[i] + k;
            while (j < N && nums[j] - k <= v) {
                ++j;
            }
            ans = std::max(ans, j - i);
        }
        return ans;
    }
};