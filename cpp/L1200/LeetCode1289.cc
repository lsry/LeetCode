#include <vector>
using std::vector;
#include <limits>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int N = grid.size();
        if (N == 1) {
            return grid[0][0];
        }
        vector<vector<int>> dp(2, vector<int>(N, 0));
        int cur{1}, minIndex{0};
        for (int i = 0;i < N;++i) {
            int nextMin{0};
            for (int j = 0;j < N;++j) {
                if (minIndex != j) {
                    dp[cur][j] = grid[i][j] + dp[1 - cur][minIndex];
                } else {
                    int minValue{std::numeric_limits<int>::max()};
                    for (int k = 0;k < N;++k) {
                        if (k != j && dp[1 - cur][k] < minValue) {
                            minValue = dp[1 - cur][k];
                        }
                    }
                    dp[cur][j] = minValue + grid[i][j];
                }
                if (dp[cur][j] < dp[cur][nextMin]) {
                    nextMin = j;
                }
            }
            minIndex = nextMin;
            cur = 1 - cur;
        }
        return *std::min_element(dp[1 - cur].begin(), dp[1 - cur].end());
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> a{{4}};
    s.minFallingPathSum(a);
    return 0;
}
