#include <functional>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        std::priority_queue<int, vector<int>, std::greater<int>> pq;
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for (int j = 0;j < N;++j) {
            for (int i = 0;i < M;++i) {
                if (i - 1 >= 0) {
                    dp[i][j] ^= dp[i - 1][j];
                }
                dp[i][j] ^= matrix[i][j];
            }
        }
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (j - 1 >= 0) {
                    dp[i][j] ^= dp[i][j - 1];
                }
                if (pq.size() < k) {
                    pq.push(dp[i][j]);
                } else if (pq.top() < dp[i][j]) {
                    pq.pop();
                    pq.push(dp[i][j]);
                }
            }
        }
        return pq.top();
    }
};