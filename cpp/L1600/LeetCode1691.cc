#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (vector<int> &cuboid : cuboids) {
            std::sort(cuboid.begin(), cuboid.end());
        }
        std::sort(cuboids.begin(), cuboids.end(), [](auto const &v1, auto const &v2){
            return v1[0] != v2[0] ? v1[0] >= v2[0] : v1[1] >= v2[1];
        });
        std::size_t cz{cuboids.size()};
        vector<int> dp(cz, 0);
        dp[0] = cuboids[0][2];
        int ans = dp[0];
        for (std::size_t i = 1;i < cz;++i) {
            for (int j = i - 1;j >= 0;--j) {
                if (cuboids[j][0] >= cuboids[i][0] && cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2]) {
                    dp[i] = std::max(dp[i], dp[j]);
                }
            }
            dp[i] += cuboids[i][2];
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};