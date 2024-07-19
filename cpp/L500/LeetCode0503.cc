#include <stack>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::stack<int> st;
        int N = nums.size();
        vector<int> ans(N, -1);
        for (int i{0};i < 2 * N;++i) {
            int x{nums[i % N]};
            while (!st.empty() && nums[st.top()] < x) {
                int id = st.top();
                st.pop();
                ans[id] = x;
            }
            st.push(i % N);
        }
        return ans;
    }
};