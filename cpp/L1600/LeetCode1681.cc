#include <vector>
using std::vector;
#include <unordered_map>
#include <unordered_set>
#include <limits>

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        std::unordered_map<int, int> values;
        int N = nums.size();
        int gn = N / k;
        for (int mask{1};mask < (1 << N);++mask) {
            if (__builtin_popcount(mask) != gn) {
                continue;
            }
            std::unordered_set<int> st;
            int mx{std::numeric_limits<int>::min()}, mn{std::numeric_limits<int>::max()};
            for (int i = 0;i < N;++i) {
                if (((mask >> i) & 1) == 1) {
                    st.emplace(nums[i]);
                    mx = std::max(mx, nums[i]);
                    mn = std::min(mn, nums[i]);
                }
            }
            if (st.size() == gn) {
                values[mask] = mx - mn;
            }
        }
        vector<int> dp(1 << N, std::numeric_limits<int>::max());
        dp[0] = 0;
        for (int mask{0};mask < (1 << N);++mask) {
            if (dp[mask] == std::numeric_limits<int>::max()) {
                continue;
            }
            std::unordered_map<int, int> seen;
            for (int i = 0;i < N;++i) {
                if (((mask >> i) & 1) == 0) {
                    seen[nums[i]] = i;
                }
            }
            if (seen.size() < gn) {
                continue;
            }
            int sub{0};
            for (auto const &[num, id] : seen) {
                sub |= (1 << id);
            }
            for (int nxt{sub};nxt != 0;nxt = (nxt - 1) & sub) {
                if (values.find(nxt) != values.end()) {
                    dp[mask | nxt] = std::min(dp[mask | nxt], dp[mask] + values[nxt]);
                }
            }
        }
        return dp[(1 << N) - 1] < std::numeric_limits<int>::max() ? dp[(1 << N) - 1] : -1;
    }
};