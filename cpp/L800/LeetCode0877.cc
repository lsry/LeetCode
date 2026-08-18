#include <vector>
using std::vector;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = 0;i < N;++i) {
            dp[i][i] = piles[i];
        }
        for (int i = N - 1;i >= 0;--i) {
            for (int j = i;j < N;++j) {
                int x1 = piles[i] - (i + 1 >= N ? 0 : dp[i + 1][j]);
                int x2 = piles[j] - (j - 1 < 0 ? 0 : dp[i][j - 1]);
                dp[i][j] = std::max(x1, x2);
            }
        }
        return dp[0][N - 1] > 0;
    }
};
