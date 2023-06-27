#include <vector>
using std::vector;
#include <limits>

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int N1 = cost.size(), N2 = cost[0].size();
        int M = 1 << N2;
        vector<vector<int>> dp(N1 + 1, vector<int>(M, std::numeric_limits<int>::max() / 2));
        dp[0][0] = 0;
        for (int i = 1;i <= N1;++i) { // current node
            for (int j = 1;j < M;++j) {  // to judge if ith node connects to the node in set2
                for (int k = 0;k < N2;++k) { // to solve how much cost when ith connects to kth node
                    if (((j >> k) & 1) == 0) {
                        continue;
                    }
                    int t = dp[i][j ^ (1 << k)]; // the kth node wasn't judged
                    t = std::min(t, dp[i - 1][j ^ (1 << k)]); // the kth node hasn't been connected by any previous i - 1 nodes
                    t = std::min(t, dp[i - 1][j]);  // the kth node was connected by one or many previous i - 1 nodes
                    dp[i][j] = std::min(t + cost[i - 1][k], dp[i][j]);
                }
            }
        }
        return dp[N1][M - 1];
    }
};