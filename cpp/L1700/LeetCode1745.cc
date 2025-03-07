#include <algorithm>
#include <string>
#include <vector>
using std::string;

class Solution {
    void isPaindrome(string const &s, std::vector<std::vector<bool>> &palind) {
        int N = s.size();
        for (int i = 0;i < N;++i) {
            for (int j = i;j >= 0;--j) {
                if (i - j <= 1) {
                    palind[j][i] = s[i] == s[j];
                } else {
                    palind[j][i] = s[i] == s[j] && palind[j + 1][i - 1];
                }
            }
        }
    }
public:
    bool checkPartitioning(string s) {
        int N = s.size();
        std::vector<std::vector<bool>> palind(N, std::vector<bool>(N, false));
        isPaindrome(s, palind);
        std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(4, false));
        dp[0][0] = true;
        for (int i = 1;i <= N;++i) {
            for (int k = 1;k <= std::min(i, 3);++k) {
                for (int j = i;j >= 1;--j) {
                    if (dp[j - 1][k - 1] && palind[j - 1][i - 1]) {
                        dp[i][k] = true;
                        break;
                    }
                }
            }
        }
        return dp[N][3];
    }
};