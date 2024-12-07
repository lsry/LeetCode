#include <vector>
using std::vector;

class Solution {
public:
    /**
     * @brief 二分，包含目标数字的那半部分的长度为奇数，否则为偶数
     */
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size();
        int sz = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (m - 1 >= 0 && nums[m - 1] == nums[m]) {
                if ((m - 1) % 2 == 0) {
                    l = m + 1;
                } else {
                    r = m - 2;
                }
            } else if (m + 1 < sz && nums[m + 1] == nums[m]) {
                if ((sz - (m + 2)) % 2 == 0) {
                    r = m - 1;
                } else {
                    l = m + 2;
                }
            } else {
                return nums[m];
            }
        }
        return nums[l];
    }
};