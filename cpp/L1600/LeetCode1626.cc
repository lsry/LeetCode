#include <vector>
using std::vector;
#include <numeric>
#include <algorithm>

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        std::size_t n{scores.size()};
        if (scores.empty()) {
            return 0;
        }
        vector<int> dp(n, 0);
        vector<std::size_t> ids(n, 0);
        for (std::size_t i{0};i < n;++i) {
            ids[i] = i;
        }
        std::stable_sort(ids.begin(), ids.end(), [&](std::size_t i, std::size_t j) {
            return ages[i] == ages[j] ? scores[i] <= scores[j] : ages[i] < ages[j];
        });
        int ans{0};
        for (std::size_t i{0};i < n;++i) {
            for (int j = i - 1;j >= 0;--j) {
                if (ages[ids[j]] == ages[ids[i]] || scores[ids[j]] <= scores[ids[i]]) {
                    dp[i] = std::max(dp[i], dp[j]);
                }
            }
            dp[i] += scores[ids[i]];
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};