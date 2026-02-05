#include <vector>
using std::vector;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans(sz, -1);
        for (int i = 0;i < sz;++i) {
            if (nums[i] % 2 == 0) {
                continue;
            }
            int t = ~nums[i];
            ans[i] = nums[i] ^ (t & -t) >> 1;
        }
        return ans;
    }
};
