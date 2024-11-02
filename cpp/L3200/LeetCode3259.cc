#include <vector>
using std::vector;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int N = energyDrinkA.size();
        vector<vector<long long>> dp(2, vector<long long>(N + 1, 0LL));
        for (int i = 1;i <= N;++i) {
            dp[0][i] = std::max(dp[0][i - 1], i - 2 >= 0 ? dp[1][i - 2] : 0) + energyDrinkA[i - 1];
            dp[1][i] = std::max(dp[1][i - 1], i - 2 >= 0 ? dp[0][i - 2] : 0) + energyDrinkB[i - 1];
        }      
        return std::max(dp[0][N], dp[1][N]);
    }
};