#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
    static constexpr unsigned long long int MOD{1'000'000'007ULL};
public:
    int countNicePairs(vector<int>& nums) {
        std::unordered_map<int, int> map;
        unsigned long long int ans{0ULL};
        for (int num : nums) {
            int numRev = 0;
            int x = num;
            while (x != 0) {
                numRev = numRev * 10 + x % 10;
                x /= 10;
            }
            int r{num - numRev};
            auto it{map.find(r)};
            if (it != map.end()) {
                ans = (ans + it->second) % MOD;
            }
            map[r] += 1;
        }
        return static_cast<int>(ans);
    }
};