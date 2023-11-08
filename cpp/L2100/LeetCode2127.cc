#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int const N = favorite.size();
        vector<int> indeg(N, 0);
        for (int i = 0;i < N;++i) {
            indeg[favorite[i]] += 1;
        }
        std::queue<int> q;
        for (int i = 0;i < N;++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<bool> used(N, false);
        vector<int> dp(N, 1);
        while (!q.empty()) {
            int node{q.front()};
            q.pop();
            used[node] = true;
            int v = favorite[node];
            dp[v] = std::max(dp[v], dp[node] + 1);
            --indeg[v];
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
        int ring{0}, total{0};
        for (int i = 0;i < N;++i) {
            if (used[i]) {
                continue;
            }
            if (favorite[favorite[i]] == i) {
                total += dp[i] + dp[favorite[i]];
                used[i] = true;
                used[favorite[i]] = true;
            } else {
                int u{i}, cnt{0};
                while (true) {
                    ++cnt;
                    u = favorite[u];
                    used[u] = true;
                    if (u == i) {
                        break;
                    }
                }
                ring = std::max(ring, cnt);
            }
        }
        return std::max(ring, total);
    }
};