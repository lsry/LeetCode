#include <vector>
using std::vector;
#include <algorithm>

class Solution {
    constexpr static int INF{0x3f3f3f3f};
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        std::stable_sort(arr2.begin(), arr2.end());
        std::size_t n1{arr1.size()}, n2{arr2.size()};
        std::size_t mn{std::min(n1, n2)};
        vector<vector<int>> dp(n1 + 1, vector<int>(mn + 1, INF));
        std::fill(dp[0].begin(), dp[0].end(), -1);
        for (std::size_t i{1};i <= n1;++i) {
            for (std::size_t j{0};j <= mn;++j) {
                if (arr1[i - 1] > dp[i - 1][j]) {
                    dp[i][j] = std::min(dp[i][j], arr1[i - 1]);
                }
                if (j == 0 || dp[i - 1][j - 1] == INF) {
                    continue;
                }
                auto it{std::upper_bound(arr2.begin(), arr2.end(), dp[i - 1][j - 1])};
                if (it != arr2.end()) {
                    dp[i][j] = std::min(dp[i][j], *it);
                }
            }
        }
        for (std::size_t j{0};j <= mn;++j) {
            if (dp[n1][j] != INF) {
                return j;
            }
        }
        return -1;
    }
};