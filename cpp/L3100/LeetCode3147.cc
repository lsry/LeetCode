#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int sz = energy.size();
        vector<int> dp(sz, 0);
        int ans{std::numeric_limits<int>::min()};
        for (int i = 0;i < sz;++i) {
            dp[i] += energy[i];
            if (i + k < sz && dp[i] > 0) {
                dp[i + k] += dp[i];
            } else if (i + k >= sz) {
                ans = std::max(ans, dp[i]);
            }
        }      
        return ans;
    }
};