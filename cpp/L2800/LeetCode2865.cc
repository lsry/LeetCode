#include <vector>
using std::vector;
#include <stack>

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int hz = maxHeights.size();
        std::stack<int> st;
        vector<long long> suffixSum(hz, 0LL);
        for (int i = hz - 1;i >= 0;--i) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i]) {
                st.pop();
            }
            if (st.empty()) {
                suffixSum[i] = static_cast<long long>(maxHeights[i]) * (hz - i);
            } else {
                int id = st.top();
                suffixSum[i] = static_cast<long long>(maxHeights[i]) * (id - i) + suffixSum[id];
            }
            st.push(i);
        }
        std::stack<int> st2;
        vector<long long> prefixSum(hz, 0);
        for (int i = 0;i < hz;++i) {
            while (!st2.empty() && maxHeights[st2.top()] > maxHeights[i]) {
                st2.pop();
            }
            if (st2.empty()) {
                prefixSum[i] = static_cast<long long>(maxHeights[i]) * (i + 1);
            } else {
                int id = st2.top();
                prefixSum[i] = static_cast<long long>(maxHeights[i]) * (i - id) + prefixSum[id];
            }
            st2.push(i);
        }
        long long ans{0LL};
        for (int i = 0;i < hz;++i) {
            long long cur = prefixSum[i] + suffixSum[i] - maxHeights[i];
            ans = std::max(cur, ans);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v{5,3,4,1,1};
    s.maximumSumOfHeights(v);
    return 0;
}
