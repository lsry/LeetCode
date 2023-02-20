#include <cmath>
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        std::size_t nz{nums.size()};
        if (nz == 0) {
            return false;
        }
        int x{nums[0]};
        for (std::size_t i{1};i < nz;++i) {
            x = std::__gcd(x, nums[i]);
        }
        return x;
    }
};