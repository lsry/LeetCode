#include <vector>
using std::vector;
#include <deque>

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        std::size_t nz{nums.size()};
        int ans = nums.size() + 1;
        std::vector<signed long long int> preSum(nz + 1, 0ll);
        for (std::size_t i{1};i <= nz;++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        std::deque<std::size_t> dq;
        dq.push_back(0);
        for (std::size_t i{1};i <= nz;++i) {
            while (!dq.empty() && preSum[i] - preSum[dq.front()] >= k) {
                ans = std::min(ans, (int)i - (int)dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && preSum[dq.back()] >= preSum[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans == nz + 1 ? -1 : ans;
    }
};