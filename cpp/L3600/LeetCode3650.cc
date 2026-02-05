#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<std::pair<int, int>>> adjoints(n, std::vector<std::pair<int, int>>());
        for (std::vector<int> const &edge : edges) {
            adjoints[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
            adjoints[edge[1]].push_back(std::make_pair(edge[0], 2 * edge[2]));
        }
        std::vector<bool> visited(n, false);
        auto fn = [](vector<int> const &p1, vector<int> const &p2) {
            return p1[1] > p2[1];
        };
        std::priority_queue<vector<int>, std::vector<vector<int>>, decltype(fn)> pq(fn);
        pq.push(vector<int>{0, 0, 0});
        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            if (visited[cur[0]]) {
                continue;
            }
            visited[cur[0]] = true;
            if (cur[0] == n - 1) {
                return cur[2];
            }
            for (std::pair<int, int> const &p : adjoints[cur[0]]) {
                if (visited[p.first]) {
                    continue;
                }
                pq.push(vector<int>{p.first, p.second + cur[2], cur[2] + p.second});
            }
        }
        return -1;
    }
};
