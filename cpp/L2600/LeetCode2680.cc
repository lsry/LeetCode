#include <vector>
using std::vector;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int N = nums.size();
        vector<long long> suffix(N + 1, 0);
        for (int i = N - 1;i >= 0;--i) {
            suffix[i] = suffix[i + 1] | static_cast<long long>(nums[i]);
        }         
        long long ans{0LL};
        long long prefix{0LL};
        for (int i = 0;i < N;++i) {
            ans = std::max(ans, prefix | (static_cast<long long>(nums[i]) << k) | suffix[i + 1]);
            prefix |= nums[i];
        }
        return ans;
    }
};