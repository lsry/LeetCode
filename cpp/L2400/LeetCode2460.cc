#include <vector>
using std::vector;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int rlow{-1}, rhigh{0};
        int N = nums.size();
        for (;rhigh < N - 1;++rhigh) {
            if (nums[rhigh] == 0) {
                continue;
            }
            ++rlow;
            if (nums[rhigh] == nums[rhigh + 1]) {
                nums[rlow] = 2 * nums[rhigh];
                nums[rhigh + 1] = 0;
                ++rhigh;
            } else {
                nums[rlow] = nums[rhigh];
            }
        }
        if (nums[N - 1] != 0) {
            ++rlow;
            nums[rlow] = nums[N - 1];
        }      
        for (++rlow;rlow < N;++rlow) {
            nums[rlow] = 0;
        }
        return nums;
    }
};