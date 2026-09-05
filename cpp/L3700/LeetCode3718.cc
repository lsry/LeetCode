#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int b{0};
        for (int num : nums) {
            if (num % k != 0) {
                continue;
            }
            if (num / k == b + 1) {
                ++b;
            }
        }
        return (b + 1) * k;
    }
};
