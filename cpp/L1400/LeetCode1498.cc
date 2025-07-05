#include <algorithm>
#include <array>
#include <iterator>
#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};
    std::array<unsigned long long int, 100005> f;
public:
    Solution() {
        f[0] = 1;
        for (int i = 1;i < 100005;++i) {
            f[i] = (f[i - 1] * 2) % MOD;
        }
    }

    int numSubseq(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        unsigned long long int ans{0ULL};
        for (auto it{nums.begin()};it != nums.end() && (*it) * 2 <= target;++it) {
            auto rit{std::upper_bound(nums.begin(), nums.end(), target - *it)};
            if (rit >= it) {
                int x = std::distance(it, rit) - 1;
                ans = (ans + f[x]) % MOD; 
            }
        }
        return ans;
    }
};