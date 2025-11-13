#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans{0};
        for (string const &str : strs) {
            int m0{0}, n1{0};
            for (char c : str) {
                if (c == '1') {
                    ++n1;
                } else {
                    ++m0;
                }
            }
            for (int i = m;i - m0 >= 0;--i) {
                for (int j = n;j - n1 >= 0;--j) {
                    // make this value max
                    dp[i][j] = std::max(dp[i][j], dp[i - m0][j - n1] + 1);
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
