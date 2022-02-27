#include <vector>
using std::vector;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        if (nums.size() < 2) {
            return -1;
        }
        int diff = -1;
        int min = nums[0];
        for (const int &num : nums) {
            if (num > min) {
                diff = std::max(num - min, diff);
            } else {
                min = std::min(min, num);
            }
        }
        return diff;
    }
};