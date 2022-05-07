#include <vector>
using std::vector;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        std::size_t sz = nums.size();
        int product = 1;
        int count = 0;
        for (std::size_t i{0}, j{0};j < sz;++j) {
            product *= nums[j];
            while (i <= j && product >= k) {
                product /= nums[i];
                ++i;
            }
            if (i <= j) {
                count += j - i + 1;
            }
        }
        return count;
    }
};