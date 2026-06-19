#include <cstdlib>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        std::size_t N{nums.size()};
        vector<int> ans(N, 0);
        int leftSum{0};
        for (std::size_t i{0uz};i < N;++i) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }
        leftSum = 0;
        for (int i = N - 1;i >= 0;--i) {
            ans[i] = std::abs(ans[i] - leftSum);
            leftSum += nums[i];
        }
        return ans;
    }
};
