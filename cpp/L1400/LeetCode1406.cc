#include <limits>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int N = stoneValue.size();
        vector<int> dp(N, 0);
        for (int i = N - 1;i >= 0;--i) {
            int x1 = stoneValue[i] - (i + 1 < N ? dp[i + 1] : 0);
            int x2 = std::numeric_limits<int>::min();
            if (i + 1 < N) {
                x2 = stoneValue[i] + stoneValue[i + 1] - (i + 2 < N ? dp[i + 2] : 0);
            }
            int x3 = std::numeric_limits<int>::min();
            if (i + 1 < N && i + 2 < N) {
                x3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - (i + 3 < N ? dp[i + 3] : 0);
            }
            dp[i] = std::max(x1, std::max(x2, x3));
        }
        return dp[0] > 0 ? "Alice" : (dp[0] == 0 ? "Tie" : "Bob");
    }
};
