#include <vector>
using std::vector;
#include <numeric>
#include <unordered_map>

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unsigned long long int sums{std::accumulate(nums.begin(), nums.end(), 0ULL)};
        if (sums < p) {
            return -1;
        }
        if (sums % p == 0) {
            return 0;
        }
        int target = static_cast<int>(sums % p);
        std::size_t nz{nums.size()};
        std::unordered_map<int, int> map;
        map[0] = -1;
        int sum{0};
        int ans = nz;
        for (int i{0};i < nz;++i) {
            sum = (sum + nums[i]) % p;
            auto it{map.find((sum - target + p) % p)};
            if (it != map.end()) {
                ans = std::min(ans, i - it->second);
            }
            map[sum] = i;
        }
        return ans == nz ? -1 : ans;
    }
};