#include <vector>
using std::vector;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans{0};
        int N = nums.size();
        for (int i = 0;i < N;) {
            int j{i + 1};
            while (j < N && nums[j] > nums[j - 1]) {
                ++j;
            }
            ans = std::max(ans, j - i);
            i = j;
        }
        for (int i = 0;i < N;) {
            int j{i + 1};
            while (j < N && nums[j] < nums[j - 1]) {
                ++j;
            }
            ans = std::max(ans, j - i);
            i = j;
        }
        return ans;
    }
};
