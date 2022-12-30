#include <vector>
using std::vector;

#include <numeric>
#include <algorithm>

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxCount = *std::max_element(nums.begin(), nums.end());
        int left = 1, right = maxCount;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int ops = 0;
            for (int num : nums) {
                ops += (num - 1) / mid;
            }
            if (ops <= maxOperations) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};