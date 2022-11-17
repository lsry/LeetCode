#include <vector>
using std::vector;

#include <algorithm>

class Solution {
    constexpr static int MOD{1'000'000'007};
public:
    int sumSubseqWidths(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::size_t nz{nums.size()};
        vector<long long int> pow2(nz, 0LL);
        pow2[0] = 1LL;
        for (std::size_t i{1};i < nz;++i) {
            pow2[i] = (pow2[i - 1] << 1) % MOD;
        }
        long long int ans{0};
        for (std::size_t i{0};i < nz;++i) {
            ans = (ans + (pow2[i] - pow2[nz - i - 1]) * nums[i] % MOD) % MOD;
        }
        return int(ans);
    }
};