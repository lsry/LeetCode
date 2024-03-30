#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int N = nums.size();
        int ans{std::numeric_limits<int>::max()};
        vector<int> lefts(N, 0);
        int Nmin{std::numeric_limits<int>::max()};
        for (int i = 0;i < N;++i) {
            lefts[i] = Nmin;
            Nmin = std::min(Nmin, nums[i]);
        }
        Nmin = std::numeric_limits<int>::max();
        for (int i = N - 1;i >= 0;--i) {
            if (nums[i] > lefts[i] && nums[i] > Nmin) {
                ans = std::min(ans, nums[i] + lefts[i] + Nmin);
            }
            Nmin = std::min(Nmin, nums[i]);
        }
        return ans == std::numeric_limits<int>::max() ? -1 : ans;
    }
};