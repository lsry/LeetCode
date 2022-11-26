#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    bool check(vector<int>& nums) {
        int nz = nums.size();
        int mi = 0;
        for (int i = 1;i < nz;++i) {
            if (nums[i] <= nums[mi]) {
                mi = i;
            }
        }
        while (mi - 1 >= 0 && nums[mi] == mi - 1) {
            --mi;
        }
        for (int i = (mi + 1) % nz;i != mi;i = (i + 1) % nz) {
            int li = (i - 1 + nz) % nz;
            if (nums[i] < nums[li]) {
                return false;
            }
        }
        return true;
    }
};