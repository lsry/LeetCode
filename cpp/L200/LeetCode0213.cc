#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    int robRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
        int a{0}, b{0};
        for (;begin != end;++begin) {
            int v = std::max(b, *begin + a);
            a = b;
            b = v;
        }
        return std::max(a, b);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() < 2) {
            return nums[0];
        }
        int a{robRange(nums.cbegin(), nums.cend() - 1)};
        int b{robRange(nums.cbegin() + 1, nums.cend())};
        return std::max(a, b);
    }
};