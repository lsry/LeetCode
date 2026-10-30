#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int N = nums.size();
        std::unordered_set<int> st;
        int ans{0};
        for (int i = 0;i < N;++i) {
            st.clear();
            for (int j{i};j < N;++j) {
                st.insert(nums[j]);
                ans += st.size() * st.size();
            }
        }
        return ans;
    }
};
