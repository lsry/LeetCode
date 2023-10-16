#include <functional>
#include <limits>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x{std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>())};
        x = x == std::numeric_limits<int>::min() ? std::numeric_limits<int>::min() : x & (-x);
        vector<int> ans{0, 0};
        for (int num : nums) {
            if ((num & x) != 0) {
                ans[0] = ans[0] ^ num;
            } else {
                ans[1] = ans[1] ^ num;
            }
        }
        return ans;
    }
};