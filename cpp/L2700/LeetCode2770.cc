#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum{std::accumulate(nums.begin(), nums.end(), 0LL)};
        long long int left{0};
        int nz = nums.size();
        int ans{0};
        for (int i = 0;i < nz - 1;++i) {
            left += nums[i];
            sum -= nums[i];
            if (left >= sum) {
                ++ans;
            }
        }      
        return ans;
    }
};