#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<long long int> minSum(k, std::numeric_limits<long long int>::max()/2);
        minSum[k - 1] = 0;
        long long int preSum{0LL};
        long long int ans{std::numeric_limits<long long int>::min()};
        for (int i = 0;i < N;++i) {
            preSum += nums[i];
            ans = std::max(ans, preSum - minSum[i % k]);
            minSum[i % k] = std::min(minSum[i % k], preSum);
        }
        return ans;
    }
};
