#include <vector>
using std::vector;

#include <algorithm>

class Solution {
    // 考慮袋子裏的某個值, 如果超過則肯定可以在操作次數内完成，少於則完不成
    // 於是利用二分找出在次數内的最小值
public:
    int minimumSizeBin(vector<int>& nums, int maxOperations) {
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