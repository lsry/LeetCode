#include <stack>
#include <vector>
using std::vector;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long int ans{0};
        std::stack<long long> st;
        for (auto it{nums.rbegin()};it != nums.rend();++it) {
            if (!st.empty() && st.top() >= * it) {
                long long cur = *it + st.top();
                st.pop();
                st.push(cur);
                ans = std::max(cur, ans);
            } else {
                st.push(*it);
                ans = std::max(ans, static_cast<long long>(*it));
            }
        }
        return ans;
    }
};