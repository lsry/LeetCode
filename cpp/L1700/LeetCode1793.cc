#include <stack>
#include <vector>
using std::vector;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int N = nums.size();
        vector<vector<int>> ps(2, vector<int>(N, 0));
        std::stack<int> st;
        for (int i = 0;i < N;++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                ps[0][i] = 0;
            } else {
                ps[0][i] = st.top() + 1;
            }
            st.push(i);
        }
        std::stack<int> st2;
        for (int i = N - 1;i >= 0;--i) {
            while (!st2.empty() && nums[st2.top()] >= nums[i]) {
                st2.pop();
            }
            if (st2.empty()) {
                ps[1][i] = N - 1;
            } else {
                ps[1][i] = st2.top() - 1;
            }
            st2.push(i);
        }
        int ans{0};
        for (int i = 0;i < N;++i) {
            if (ps[0][i] <= k && ps[1][i] >= k) {
                ans = std::max(ans, (ps[1][i] - ps[0][i] + 1) * nums[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a{1,4,3,7,4,5};
    s.maximumScore(a, 3);
}