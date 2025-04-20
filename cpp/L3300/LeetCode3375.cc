#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if (nums.empty()) {
            return -1;
        }
        int N = nums.size();
        std::sort(nums.begin(), nums.end());
        if (nums[0] < k) {
            return -1;
        }
        int ans{0};
        for (int i = N - 1;i >= 0;--i) {
            while (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                --i;
            }
            ++ans;
        }
        return nums[0] == k ? ans - 1 : ans;
    }
};