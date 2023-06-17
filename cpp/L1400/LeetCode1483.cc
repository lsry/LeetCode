#include <vector>
using std::vector;

class TreeAncestor {
    constexpr static int N{16};
    vector<vector<int>> dp;
public:
    TreeAncestor(int n, vector<int>& parent): dp(n, vector<int>(N, -1)) {
        for (int i = 0;i < n;++i) {
            dp[i][0] = parent[i];
        }
        for (int i = 1;i < N;++i) {
            for (int j = 0;j < n;++j) {
                if (dp[j][i - 1] != -1) {
                    dp[j][i] = dp[dp[j][i - 1]][i - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int p{node};
        for (int i = 0;i < N && p != -1;++i) {
            if (((k >> i) & 1) == 1) {
                p = dp[p][i];
            }
        }
        return p;
    }
};
