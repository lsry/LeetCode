#include <vector>
using std::vector;
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        std::stable_sort(nums.begin(), nums.end());
        std::unordered_set<int> set;
        for (int i = 0, j = nums.size() - 1;i < j;++i, --j) {
            set.insert(nums[i] + nums[j]);
        }
        return set.size();
    }
};