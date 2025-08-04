#include <vector>
using std::vector;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans{0};
        int N = nums.size();
        for (int i = 1;i < N;) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            int j{i};
            while (j < N && nums[j] == nums[i]) {
                ++j;
            }
            if (j >= N) {
                break;
            }
            if ((nums[i - 1] < nums[i] && nums[j] < nums[i]) || (nums[i - 1] > nums[i] && nums[j] > nums[i])) {
                ++ans;
            }
            i = j;
        }
        return ans;
    }
};