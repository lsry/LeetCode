#include <algorithm>
#include <functional>
#include <vector>
using std::vector;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        int N = nums.size();
        for (int i = 0;i < N - 2;++i) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};