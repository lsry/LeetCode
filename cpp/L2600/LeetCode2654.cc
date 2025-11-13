#include <limits>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        int nz = nums.size();
        int one{0};
        if (nz == 1) {
            return nums[0] == 1 ? 0 : -1;
        }
        int gcdNum{nums[0]};
        for (int i = 0;i < nz;++i) {
            gcdNum = std::gcd(gcdNum, nums[i]);
            if (nums[i] == 1) {
                ++one;
            }
        }
        if (one > 0) {
            return nz - one;
        }
        if (gcdNum > 1) {
            return -1;
        }
        int ans{std::numeric_limits<int>::max()};
        for (int i = 0;i < nz;++i) {
            gcdNum = nums[i];
            for (int j = i;j < nz;++j) {
                gcdNum = std::gcd(gcdNum, nums[j]);
                if (gcdNum == 1) {
                    ans = std::min(ans, j - i + 1 + nz - 2);
                    break;
                }
            }
        }
        return ans == std::numeric_limits<int>::max() ? -1 : ans;
    }
};
