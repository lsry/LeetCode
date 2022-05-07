#include <vector>
using std::vector;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int sz = nums.size();
        for (int i = -1,j = 0;j < sz;++j) {
            if (nums[j] % 2 == 0) {
                ++i;
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
        return nums;
    }
};