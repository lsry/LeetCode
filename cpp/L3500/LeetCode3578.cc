#include <cstddef>
#include <set>
#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int countPartitions(vector<int>& nums, int k) {
        std::multiset<int> st;
        std::size_t N{nums.size()};
        std::vector<unsigned long long int> dp(N + 1, 0);
        dp[0] = 1;
        std::vector<unsigned long long int> prefix(N + 1, 0);
        prefix[0] = 1;
        for (int i = 0, j = 0;i < N;++i) {
            st.emplace(nums[i]);
            while (j <= i && *st.rbegin() - *st.begin() > k) {
                st.erase(st.find(nums[j]));
                ++j;
            }
            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + MOD) % MOD;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % MOD;
        }
        return dp[N];
    }
};
