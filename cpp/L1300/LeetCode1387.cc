#include <algorithm>
#include <array>
#include <vector>
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        std::array<int, 1001> dp{-1};
        std::fill(dp.begin(), dp.end(), -1);
        dp[0] = 0, dp[1] = 0;
        for (int i = 2;i <= 1000;++i) {
            int step = 0;
            int x = i;
            while (x != 1) {
                if (x % 2 == 0) {
                    x /= 2;
                } else {
                    x = 3 * x + 1;
                }
                ++step;
            }
            dp[i] = step;
        }
        std::vector<int> nums;
        for (int i = lo;i <= hi;++i) {
            nums.push_back(i);
        }
        std::sort(nums.begin(), nums.end(), [&](int a, int b) {
            return dp[a] == dp[b] ? a < b : dp[a] < dp[b];
        });
        return nums[k - 1];
    }
};