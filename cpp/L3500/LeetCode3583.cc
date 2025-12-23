#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};
public:
    int specialTriplets(vector<int>& nums) {
        std::unordered_map<int, int> pre, suf;
        for (int num : nums) {
            suf[num] += 1;
        }
        unsigned long long int ans{0ULL};
        for (int num : nums) {
            suf[num] -= 1;
            int p = pre[num * 2];
            int s = suf[num * 2];
            ans = (ans + (1ULL * p * s) % MOD) % MOD;
            pre[num] += 1;
        }
        return ans;
    }
};
