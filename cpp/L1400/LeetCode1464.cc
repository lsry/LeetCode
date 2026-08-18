#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        return std::max((nums[N - 1] - 1) * (nums[N - 2] - 1), (nums[0] - 1) * (nums[1] - 1));
    }
};
