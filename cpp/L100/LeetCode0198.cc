#include <algorithm>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
/**
 * dp[i]: 偷盜第 i 閒房子可以得到的總金額
 * 1. 偷當前房子和前 i-2 閒房子的金額
 * 2. 不偷當前房子，偷前 i-1閒屋子       
 * Q: 爲什麽不考慮 i-3, i-4 及更前面的屋子？    
 * A：因爲 dp[i-2] = max(dp[i - 3], dp[i - 4] + nums[i - 2]) 包含了 i-4，
 *         dp[i-1] = max(dp[i - 2], dp[i - 3] + nums[i - 1]) 包含了 i-3.
 *    其他同理
 */
    int rob(vector<int>& nums) {
        int a{0}, b{0};
        for (int num : nums) {
            int v = std::max(a + num, b);
            a = b;
            b = v;
        }
        return std::max(a, b);
    }
};