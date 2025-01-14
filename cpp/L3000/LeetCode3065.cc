#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        auto it{std::lower_bound(nums.begin(), nums.end(), k)};
        return std::distance(nums.begin(), it);
    }
};