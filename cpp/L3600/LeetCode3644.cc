#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = std::numeric_limits<int>::max();
        int N = nums.size();
        for (int i = 0;i < N;++i) {
            if (nums[i] != i) {
                k = k & nums[i];
            }
        }
        return k == std::numeric_limits<int>::max() ? 0 : k;
    }
};
