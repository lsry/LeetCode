#include <vector>
using std::vector;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int N = nums.size();
        int ans{0};
        for (int i = 1;i < N - 1;++i) {
            if (nums[i] % 2 == 0 && nums[i] / 2 == nums[i + 1] + nums[i - 1]) {
                ++ans;
            }
        }
        return ans;
    }
};