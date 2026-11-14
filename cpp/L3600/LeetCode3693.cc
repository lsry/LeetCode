#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> ans(n + 1, std::numeric_limits<int>::max());
        ans[0] = 0;
        for (int i = 1;i <= n;++i) {
            if (i - 1 >= 0) {
                ans[i] = std::min(ans[i], costs[i - 1] + 1 + ans[i - 1]);
            }
            if (i - 2 >= 0) {
                ans[i] = std::min(ans[i], costs[i - 1] + 4 + ans[i - 2]);
            }
            if (i - 3 >= 0) {
                ans[i] = std::min(ans[i], costs[i - 1] + 9 + ans[i - 3]);
            }
        }
        return ans[n];
    }
};
