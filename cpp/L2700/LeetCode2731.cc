#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
    constexpr static long long int MOD{1'000'000'007};
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        std::size_t n{nums.size()};
        for (std::size_t i{0};i < n;++i) {
            if (s[i] == 'L') {
                nums[i] -= d;
            } else {
                nums[i] += d;
            }
        }
        std::sort(nums.begin(), nums.end());
        long long int ans{0LL}, sum{nums[0]};
        for (long long int i{1LL};i < n;++i) {
            long long int temp{static_cast<long long int>(nums[i]) * i - sum};
            ans = (ans + temp) % MOD;
            sum += nums[i];
        }
        return static_cast<int>(ans);
    }
};