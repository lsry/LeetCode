#include <queue>
#include <vector>
using std::vector;
class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int N = edges.size() + 1;
        vector<vector<int>> adjoints(N, vector<int>());
        for (vector<int> const &edge : edges) {
            adjoints[edge[0] - 1].emplace_back(edge[1] - 1);
            adjoints[edge[1] - 1].emplace_back(edge[0] - 1);
        }
        int depth{0};
        std::queue<int> q;
        q.push(0);
        vector<bool> visited(N, false);
        visited[0] = true;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0;i < sz;++i) {
                int node = q.front();
                q.pop();
                visited[node] = true;
                for (int next : adjoints[node]) {
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            ++depth;
        }
        unsigned long long int ans{1ULL};
        for (int i = 0;i < depth - 2;++i) {
            ans = (ans * 2) % MOD;
        }
        return static_cast<int>(ans);
    }
};
