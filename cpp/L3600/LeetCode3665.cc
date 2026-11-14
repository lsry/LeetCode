#include <vector>
using std::vector;

class Solution {
    using ULL_T = unsigned long long int;
    constexpr static ULL_T MOD{1'000'000'007ULL};
public:
    int uniquePaths(vector<vector<int>>& grid) {
        if (grid.size() <= 0 || grid[0].size() <= 0) {
            return 0;
        }
        int M = grid.size(), N = grid[0].size();
        // 0: top, 1: left
        vector<vector<ULL_T>> dp(N, vector<ULL_T>(2, 0ULL));
        dp[0][0] = 1ULL;
        dp[0][1] = 1ULL;
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                ULL_T top{0ULL}, left{0ULL};
                if (i - 1 >= 0) {
                    if (grid[i - 1][j] == 0) {
                        top = (top + dp[j][0]) % MOD;
                    } else {
                        top = (top + dp[j][1]) % MOD;
                    }
                }
                if (j - 1 >= 0) {
                    left = (left + dp[j - 1][0]) % MOD;
                }
                if (grid[i][j] == 0) {
                    dp[j][0] = (left + top) % MOD;
                    dp[j][1] = 0ULL;
                } else {
                    dp[j][0] = top;
                    dp[j][1] = left;
                }
            }
        }
        return static_cast<int>((dp[N - 1][0] + dp[N - 1][1]) % MOD);
    }
};

int main() {
    vector<vector<int>> g{{0,1,0},{0,0,1},{1,0,0}};
    Solution s;
    s.uniquePaths(g);
}
