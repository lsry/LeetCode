#include <vector>
using std::vector;
#include <array>

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        std::array<int, 1 << 16> cnt{{0}};
        std::size_t nz{nums.size()};
        for (std::size_t i{0};i < nz;++i) {
            for (std::size_t j{0};j < nz;++j) {
                cnt[nums[i] & nums[j]] ++;
            }
        }
        int ans{0};
        for (int num : nums) {
            int x{num ^ 0xffff};
            for (int m{x};m > 0;m = (m - 1) & x) {
                ans += cnt[m];
            }
            ans += cnt[0];
        }
        return ans;
    }
};