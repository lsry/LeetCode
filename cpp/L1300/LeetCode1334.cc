#include <float.h>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    int dijstra(int n, vector<vector<std::pair<int, int>>> const &adjoints, int node, int distanceThreshold) {
        int cities{0};
        auto fn{[](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
            return p1.second > p2.second;
        }};
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(fn)> pq(fn);
        pq.push({node, 0});
        vector<bool> flags(n, false);
        while (!pq.empty()) {
            auto [p, d] = pq.top();
            pq.pop();
            if (flags[p] || d > distanceThreshold) {
                continue;
            }
            ++cities;
            flags[p] = true;
            for (std::pair<int, int> const &next : adjoints[p]) {
                if (!flags[next.first] && next.second + d <= distanceThreshold) {
                    pq.push({next.first, d + next.second});
                }
            }
        }
        return cities;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<std::pair<int, int>>> adjoints(n, vector<std::pair<int, int>>());
        for (vector<int> const &edge : edges) {
            adjoints[edge[0]].push_back({edge[1], edge[2]});
            adjoints[edge[1]].push_back({edge[0], edge[2]});
        }
        int ans{-1}, city{n + 1};
        for (int i = 0;i < n;++i) {
            int c = dijstra(n, adjoints, i, distanceThreshold);
            if (c <= city) {
                city = c;
                ans = i;
            }
        }
        return ans;
    }
};