#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> rightMin(N, 0);
        for (int lastMin{std::numeric_limits<int>::max()}, i = N - 1;i >= 0;--i) {
            lastMin = std::min(lastMin, nums[i]);
            rightMin[i] = lastMin;
        }
        for (int lastMax{std::numeric_limits<int>::min()}, i = 0;i < N;++i) {
            lastMax = std::max(lastMax, nums[i]);
            if (lastMax - rightMin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
