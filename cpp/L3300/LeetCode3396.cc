#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ix = -1;
        std::unordered_set<int> st;
        for (int i = nums.size() - 1;i >= 0;--i) {
            if (st.contains(nums[i])) {
                ix = i;
                break;
            } else {
                st.emplace(nums[i]);
            }
        }
        return ix == -1 ? 0 : ix / 3 + 1;
    }
};