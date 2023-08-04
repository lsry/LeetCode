#include <vector>
using std::vector;
#include <algorithm>

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};
public:
    int sumOfPower(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        unsigned long long int ans{0ULL};
        unsigned long long int S{0ULL}, s{0ULL};
        for (int i{0};i < N;++i) {
            s = (s * 2) % MOD;
            if (i - 2 >= 0) {
                s = (s + nums[i - 2]) % MOD;
            }
            S = (S + nums[i] + s) % MOD;
            ans = (ans + (((static_cast<unsigned long long int>(nums[i]) * nums[i]) % MOD) * S) % MOD) % MOD;
        }
        return static_cast<int>(ans);
    }
};