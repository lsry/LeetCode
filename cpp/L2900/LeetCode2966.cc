#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0;i < nums.size();i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            res.emplace_back(vector<int>{nums[i], nums[i + 1], nums[i + 2]});
        }      
        return res;
    }
};