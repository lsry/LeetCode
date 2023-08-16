#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
    constexpr static long long int MOD{1'000'000'007LL};
    int M, N;
    long long int splitPisa(vector<string> const &pizza, int row, int col, vector<vector<vector<long long int>>> &dp, int k, int total) {
        if (k == 1 && total > 0) {
            return 1;
        } else if (total <= 0 || k <= 0 || row >= M || col >= N) {
            return 0;
        }
        if (dp[row][col][k] != -1) {
            return dp[row][col][k];
        }
        long long int res{0LL};
        int apple{0};
        for (int r{row};r < M;++r) {
            for (int c{col};c < N;++c) {
                if (pizza[r][c] == 'A') {
                    ++apple;
                }
            }
            if (apple > 0) {
                res = (res + splitPisa(pizza, r + 1, col, dp, k - 1, total - apple)) % MOD;
            }
        }
        apple = 0;
        for (int c{col};c < N;++c) {
            for (int r{row};r < M;++r) {
                if (pizza[r][c] == 'A') {
                    ++apple;
                }
            }
            if (apple > 0) {
                res = (res + splitPisa(pizza, row, c + 1, dp, k - 1, total - apple)) % MOD;
            }
        }
        dp[row][col][k] = res;
        return res;
    }
public:
    int ways(vector<string>& pizza, int k) {
       M = pizza.size();
       if (M == 0) {
        return 0;
       } 
       N = pizza[0].size();
       if (N == 0) {
        return 0;
       }
       int apple{0};
       for (int i{0};i < M;++i) {
            for (int j{0};j < N;++j) {
                if (pizza[i][j] == 'A') {
                    ++apple;
                }
            }
       }
       if (apple == 0) {
        return 0;
       }
       vector<vector<vector<long long int>>> dp(M, vector<vector<long long int>>(N, vector<long long int>(k + 1, -1)));
       long long int r{splitPisa(pizza, 0, 0, dp, k, apple)};
       return static_cast<int>(r);
    }
};