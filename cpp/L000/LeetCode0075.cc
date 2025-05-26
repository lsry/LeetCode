#include <vector>
using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = -1, j = 0, k = nums.size();j < k;++j) {
            if (nums[j] == 0) {
                ++i;
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            } else if (nums[j] == 2) {
                --k;
                int t = nums[k];
                nums[k] = nums[j];
                nums[j] = t;
                --j;
            }
        }
    }
};