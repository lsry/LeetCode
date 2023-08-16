#include <vector>
using std::vector;
#include <cmath>

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int xv{0}, iv{0};
        int sum{0};
        int ans{0};
        for (int num : nums) {
            sum += num;
            if (sum > 0) {
                ans = std::max(ans, std::abs(sum - iv));
            } else {
                ans = std::max(ans, std::abs(sum - xv));
            }
            iv = std::min(iv, sum);
            xv = std::max(xv, sum);
        }
        return ans;
    }
};