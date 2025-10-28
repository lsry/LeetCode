#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int count{0};
        int last{std::numeric_limits<int>::min()};
        for (int num : nums) {
            if (last + 1 < num - k) {
                ++count;
                last = num - k;
            } else if (last + 1 >= num - k && last + 1 <= num + k) {
                ++count;
                last = last + 1;
            }
        }
        return count;
    }
};
