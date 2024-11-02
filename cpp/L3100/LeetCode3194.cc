#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        double ans = 100.0;
        for (int low = 0, high = nums.size() - 1;low <= high;++low, --high) {
            double x = (nums[low] + nums[high]) / 2.0;
            ans = std::min(ans, x);
        }
        return ans;
    }
};