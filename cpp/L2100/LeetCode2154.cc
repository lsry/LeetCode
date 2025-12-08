#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        std::unordered_set<int> st(nums.begin(), nums.end());
        while (st.contains(original)) {
            original *= 2;
        }
        return original;
    }
};
