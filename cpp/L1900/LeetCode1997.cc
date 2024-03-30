#include <vector>
using std::vector;

class Solution {
    constexpr static long long int MOD{1'000'000'007};
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int N = nextVisit.size();
        vector<long long int> dp(N + 1, 0);
        dp[1] = 2;
        for (int i = 1;i < N;++i) {
            int next = nextVisit[i];
            dp[i + 1] = (2 * dp[i] - dp[next] + 2 + MOD) % MOD;
        }
        return dp[N - 1] % MOD;
    }
};