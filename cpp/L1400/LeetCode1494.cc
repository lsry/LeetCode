#include <vector>
using std::vector;
#include <limits>

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        int N = 1 << n;
        vector<int> dp(N, std::numeric_limits<int>::max());
        vector<int> needs(N, 0);
        for (vector<int> const &relat : relations) {
            needs[1 << (relat[1] - 1)] |= 1 << (relat[0] - 1);
        }
        dp[0] = 0;
        for (int i = 1;i < N;++i) {
            needs[i] = needs[i & (i - 1)] | needs[i & (-i)];
            if ((needs[i] | i) != i) {
                continue;
            }
            int valid = i ^ needs[i];
            if (__builtin_popcount(valid) <= k) {
                dp[i] = std::min(dp[i], dp[i ^ valid] + 1);
            } else {
                for (int sub = valid;sub != 0;sub = (sub - 1) & valid) {
                    if (__builtin_popcount(sub) <= k) {
                        dp[i] = std::min(dp[i], dp[i ^ sub] + 1);
                    }
                }
            }
        }
        return dp[N - 1];
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> c{{2,1}, {3,1}, {1, 4}};
    Solution s;
    s.minNumberOfSemesters(4, c, 2);    
    return 0;
}
