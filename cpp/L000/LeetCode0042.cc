#include <vector>
using std::vector;
#include <stack>

class Solution {
public:
   // 着重考虑三个位置，雨水区域左右边界及中间小于的部分，雨水是一层一层叠加上去的
    int trap(vector<int>& height) {
        std::stack<int> st;
        int sz = height.size();
        int ans{0};
        for (int i{0};i < sz;++i) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int top = st.top();
                while (!st.empty() && height[st.top()] == height[top]) {
                    st.pop();
                }
                if (!st.empty()) {
                    ans += (std::min(height[i], height[st.top()]) - height[top]) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(v);
    return 0;
}
