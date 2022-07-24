#include <vector>
using std::vector;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        std::size_t nz{nums.size()};
        vector<bool> flag(nz, false);
        int ans = 0;
        for (std::size_t i{0};i < nz;++i) {
            if (flag[nums[i]]) {
                continue;
            }
            int count = 0;
            for (int x{nums[i]};!flag[x];x = nums[x]) {
                ++count;
                flag[x] = true;
            }
            ans = std::max(ans, count);
        }
        return ans;
    }
};