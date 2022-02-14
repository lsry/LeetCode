#include <vector>
using std::vector;

class Solution {
public:
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