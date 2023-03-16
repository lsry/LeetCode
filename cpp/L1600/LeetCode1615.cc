#include <vector>
using std::vector;
#include <unordered_set>

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> counts(n, 0);
        vector<std::unordered_set<int>> edges(n, std::unordered_set<int>());
        for (vector<int> const &road : roads) {
            counts[road[0]] += 1;
            counts[road[1]] += 1;
            edges[road[0]].emplace(road[1]);
            edges[road[1]].emplace(road[0]);
        }
        int ans{0};
        for (int i = 0;i < n;++i) {
            for (int j = i + 1;j < n;++j) {
                int e{counts[i] + counts[j]};
                if (edges[i].count(j) > 0) {
                    e = e - 1;
                }
                ans = std::max(ans,e);
            }
        }
        return ans;
    }
};