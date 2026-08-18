#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        return std::max(nums[N - 1] * nums[N - 2] * nums[N - 3],
            nums[N - 1] * nums[0] * nums[1]);
    }
};
