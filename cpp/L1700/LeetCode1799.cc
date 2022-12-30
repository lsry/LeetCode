#include <vector>
using std::vector;
#include <cmath>
#include <numeric>

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> gcds(n, vector<int>(n, 0));
        for (int i = 0;i < n;++i) {
            for (int j = i + 1;j < n;++j) {
                gcds[i][j] = std::gcd(nums[i], nums[j]);
            }
        }
        int all = 1 << n;
        vector<int> dp(all, 0);
        for (int i = 1;i < all;++i) {
            int t = __builtin_popcount(i);
            if (t & 1) {
                continue;
            }
            for (int a = 0;a < n;++a) {
                if (((i >> a) & 1) == 0) {
                    continue;
                }
                for (int b = a + 1;b < n;++b) {
                    if (((i >> b) & 1) == 0) {
                        continue;
                    }
                    dp[i] = std::max(dp[i], dp[i ^ (1 << a) ^ (1 << b)] + (t * gcds[a][b]) / 2);
                }
            }
        }
        return dp[all - 1];
    }
};