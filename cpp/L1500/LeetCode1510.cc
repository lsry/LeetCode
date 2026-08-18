#include <vector>
class Solution {
    int trace(std::vector<int> &dp, int n) {
        if (dp[n] != 0) {
            return dp[n];
        }
        int success{-1};
        for (int i = 1;i * i <= n;++i) {
            int next = trace(dp, n - i * i);
            if (next == -1) {
                success = 1;
                break;
            }
        }
        dp[n] = success;
        return success;
    }
public:
    bool winnerSquareGame(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = -1;
        int alice = trace(dp, n);
        return alice == 1;
    }
};

int main() {
    Solution s;
    s.winnerSquareGame(2);
}
