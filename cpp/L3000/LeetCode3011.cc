#include <algorithm>
#include <bit>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    /**
    * @brief 相同 1 個數的數字進行分組，形成子數組
    */
    bool canSortArray(vector<int>& nums) {
        int N = nums.size();
        int lastMax = std::numeric_limits<int>::min();
        for (int i = 0;i < N;) {
            int j = i;
            int bitCount = std::popcount(static_cast<unsigned int>(nums[i]));
            int lowValue = nums[i];
            int maxValue = nums[i];
            while (j < N && std::popcount(static_cast<unsigned int>(nums[j])) == bitCount) {
                lowValue = std::min(lowValue, nums[j]);
                maxValue = std::max(maxValue, nums[j]);
                ++j;
            }
            if (lowValue < lastMax) {
                return false;
            }
            lastMax = std::max(lastMax, maxValue);
            i = j;
        }
        return true;
    }
};