#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
    int compute(vector<int> const &slice) {
        int N3 = slice.size();
        int N = (N3 + 1) / 3;
        vector<vector<int>> dp(N3, vector<int>(N + 1, std::numeric_limits<int>::min()));
        dp[0][0] = 0;
        dp[0][1] = slice[0];
        dp[1][0] = 0;
        dp[1][1] = std::max(slice[0], slice[1]);
        for (int i = 2;i < N3;++i) {
            dp[i][0] = 0;
            for (int j = 1;j <= N;++j) {
                dp[i][j] = std::max(dp[i - 2][j - 1] + slice[i], dp[i - 1][j]);
            }
        }
        return dp[N3 - 1][N];
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int N3 = slices.size();
        vector<int> s1(slices.begin(), slices.end() - 1);
        vector<int> s2(slices.begin() + 1, slices.end());
        return std::max(compute(s1), compute(s2));
    }
};
