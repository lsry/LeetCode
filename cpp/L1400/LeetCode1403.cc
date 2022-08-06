#include <vector>
using std::vector;
#include <algorithm>
#include <numeric>

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        vector<int> res;
        int r_sum = 0;
        for (int i = nums.size() - 1;i >= 0;--i) {
            r_sum += nums[i];
            res.push_back(nums[i]);
            if (r_sum > sum - r_sum) {
                break;
            }
        }
        return res;
    }
};