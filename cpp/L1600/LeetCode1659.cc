#include <vector>
using std::vector;

class Solution {
    int M, N;
    vector<int> pow3;

    int dfs(int pos, int state, int ti, int te, vector<vector<vector<vector<int>>>> &dp) {
        if (pos == M * N || (ti == 0 && te == 0)) {
            return 0;
        }
        if (dp[pos][state][ti][te] != -1) {
            return dp[pos][state][ti][te];
        }
        int r = 0;
        int up = state / pow3[N - 1], left = state % 3;
        r = std::max(r, dfs(pos + 1, state % pow3[N - 1] * 3, ti, te, dp));
        if (ti > 0) {
            int goal = 120;
            goal += dfs(pos + 1, state % pow3[N - 1] * 3 + 1, ti - 1, te, dp);
            if (up == 1) {
                goal -= 60;
            } else if (up == 2) {
                goal -= 10;
            }
            if (pos % N != 0) {
                if (left == 1) {
                    goal -= 60;
                } else if (left == 2) {
                    goal -= 10;
                }
            }
            r = std::max(r, goal);
        }
        if (te > 0) {
            int goal = 40;
            goal += dfs(pos + 1, state % pow3[N - 1] * 3 + 2, ti, te - 1, dp);
            if (up == 1) {
                goal -= 10;
            } else if (up == 2) {
                goal += 40;
            }
            if (pos % N != 0) {
                if (left == 1) {
                    goal -= 10;
                } else if (left == 2) {
                    goal += 40;
                }
            }
            r = std::max(r, goal);
        }
        dp[pos][state][ti][te] = r;
        return r;
    }
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        M = m;
        N = n;
        pow3 = vector<int>(N + 1, 0);
        pow3[0] = 1;
        for (int i = 1;i <= N;++i) {
            pow3[i] = pow3[i - 1] * 3;
        }
        vector<vector<vector<vector<int>>>> dp(M * N, vector<vector<vector<int>>>(pow3[N], vector<vector<int>>(introvertsCount + 1, vector<int>(extrovertsCount + 1, -1))));
        return dfs(0, 0, introvertsCount, extrovertsCount, dp);
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    s.getMaxGridHappiness(2,3,1,2);
    return 0;
}
