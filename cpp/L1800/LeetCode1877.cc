#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans{0};
        for (int low{0}, high{n - 1};low < high;++low, --high) {
            ans = std::max(ans, nums[low] + nums[high]);
        }
        return ans;
    }
};
