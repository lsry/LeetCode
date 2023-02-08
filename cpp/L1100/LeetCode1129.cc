#include <vector>
using std::vector;
#include <unordered_map>
#include <queue>
#include <numeric>

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<std::unordered_map<int, vector<int>>> map(2, std::unordered_map<int, vector<int>>());
        for (vector<int> &edge : redEdges) {
           map[0][edge[0]].push_back(edge[1]);
        }
        for (vector<int> &edge : blueEdges) {
            map[1][edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> dist(n, vector<int>(2, std::numeric_limits<int>::max()));
        dist[0][0] = 0;
        dist[0][1] = 0;
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair<int, int>(0, 0));
        q.push(std::make_pair<int, int>(0, 1));
        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();
            for (int next : map[1 - color][node]) {
                if (dist[next][1 - color] != std::numeric_limits<int>::max()) {
                    continue;
                }
                dist[next][1 - color] = dist[node][color] + 1;
                q.push(std::pair<int, int>(next, 1 - color));
            }
        }
        vector<int> res(n, -1);
        for (int i = 0;i < n;++i) {
            int x = std::min(dist[i][0], dist[i][1]);
            if (x != std::numeric_limits<int>::max()) {
                res[i] = x;
            }
        }
        return res;
    }
};