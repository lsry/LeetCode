#include <limits>
#include <string>
#include <vector>
using std::string;

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int fn = floor.size();
        std::vector<std::vector<int>> dp(fn + 1, std::vector<int>(numCarpets + 1, std::numeric_limits<int>::max()));
        for (int i = 0;i <= numCarpets;++i) {
            dp[0][i] = 0;
        }      
        for (int i = 1;i <= fn;++i) {
            dp[i][0] = dp[i - 1][0] + (floor[i - 1] == '1' ? 1 : 0);
        }
        for (int i = 1;i <= fn;++i) {
            for (int j = 1;j <= numCarpets;++j) {
                dp[i][j] = std::min(dp[i - 1][j] + (floor[i - 1] == '1' ? 1 : 0), i - carpetLen >= 0 ? dp[i - carpetLen][j - 1] : 0);
            }
        }
        return dp[fn][numCarpets];
    }
};