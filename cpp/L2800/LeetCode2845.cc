#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int N = nums.size();
        vector<int> preSum(N + 1, 0);
        for (int i = 0;i < N;++i) {
            preSum[i + 1] = preSum[i] + (nums[i] % modulo == k ? 1 : 0);
        }
        long long ans{0};
        std::unordered_map<int, long long int> mp;
        mp[0] = 1;
        for (int i = 1;i <= N;++i) {
            int ci = (preSum[i] + modulo - k) % modulo;
            ans += mp[ci];
            mp[preSum[i] % modulo] += 1;
        }
        return ans;
    }
};