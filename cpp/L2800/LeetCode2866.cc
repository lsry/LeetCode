#include <stack>
#include <vector>
using std::vector;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        vector<vector<long long>> nums(2, vector<long long>(maxHeights.size(), 0LL));
        std::stack<int> lst;
        int sz = maxHeights.size();
        for (int i = 0;i < sz;++i) {
            while (!lst.empty() && maxHeights[i] < maxHeights[lst.top()]) {
                lst.pop();
            }
            if (lst.empty()) {
                nums[0][i] = static_cast<long long>(maxHeights[i]) * (i + 1);
            } else {
                nums[0][i] = static_cast<long long>(maxHeights[i]) * (i - lst.top()) + nums[0][lst.top()];
            }
            lst.push(i);
        }
        std::stack<int> rst;
        for (int i = sz - 1;i >= 0;--i) {
            while (!rst.empty() && maxHeights[i] < maxHeights[rst.top()]) {
                rst.pop();
            }
            if (rst.empty()) {
                nums[1][i] = (sz - i) * static_cast<long long>(maxHeights[i]);
            } else {
                nums[1][i] = (rst.top() - i) * static_cast<long long>(maxHeights[i]) + nums[1][rst.top()];
            }
            rst.push(i);
        }
        long long ans{0LL};
        for (int i = 0;i < sz;++i) {
            ans = std::max(ans, nums[0][i] + nums[1][i] - maxHeights[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> h{6,5,2,1,5,4,4,2};
    Solution s;
    s.maximumSumOfHeights(h);
}