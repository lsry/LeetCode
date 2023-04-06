#include <vector>
using std::vector;
#include <unordered_set>

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int nz = nums.size();
        std::unordered_set<int> st(nums.begin(), nums.end());
        int ans{0};
        for (int i = 0;i < nz - 2;++i) {
            if (st.count(nums[i] + diff) > 0 && st.count(nums[i] + 2 * diff) > 0) {
                ++ans;
            }
        }
        return ans;
    }
};