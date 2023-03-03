#include <vector>
using std::vector;

class Solution {
    int pz{0};
    int trace(vector<int> const &sums,int M, int left, vector<vector<int>> &dp) {
        if (left >= pz - 1) {
            return 0;
        }
        if (left + 2 * M >= pz - 1) {
            return sums[pz - 1] - sums[left];
        }
        if (dp[left][M] != -1) {
            return dp[left][M];
        }
        int stones{0};
        int right = std::min(left + M * 2, pz - 1);
        for (int i = left + 1;i <= right;++i) {
            int other = trace(sums, std::max(M, i - left), i, dp);
            int next = sums[pz - 1] - sums[left] - other;
            stones = std::max(next, stones);
        }
        dp[left][M] = stones;
        return stones;
    }
public:
    int stoneGameII(vector<int>& piles) {
        pz = piles.size() + 1;
        vector<int> sums(pz, 0);
        for (int i{1};i < pz;++i) {
            sums[i] = sums[i - 1] + piles[i - 1];
        }
        vector<vector<int>> dp(pz, vector<int>(pz, -1));
        return trace(sums, 1, 0, dp);
    }
};