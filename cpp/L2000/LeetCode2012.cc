#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> suffix(nums.size(), 0);
        int minValue{std::numeric_limits<int>::max()};
        for (int i = nums.size() - 1;i >= 0;--i) {
            suffix[i] = minValue;
            minValue = std::min(minValue, nums[i]);
        }      
        int maxValue{nums[0]};
        int beautyValue{0};
        for (int i = 1;i < nums.size() - 1;++i) {
            if (nums[i] > maxValue && nums[i] < suffix[i]) {
                beautyValue += 2;
            } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                beautyValue += 1;
            }
            maxValue = std::max(maxValue, nums[i]);
        }
        return beautyValue;
    }
};