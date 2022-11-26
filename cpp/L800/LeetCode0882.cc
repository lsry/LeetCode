#include <vector>
using std::vector;

#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

class Solution {
    int encode(int x, int y, int n) {
        return x * n + y;
    }
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        std::vector<std::vector<std::pair<int, int>>> adjoints(n, std::vector<std::pair<int, int>>());
        for (vector<int> &edge : edges) {
            adjoints[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
            adjoints[edge[1]].push_back(std::make_pair(edge[0], edge[2]));
        }
        std::unordered_set<int> visited;
        std::unordered_map<int, int> nodesMap;
        auto fn = [](std::pair<int, int> const &a, std::pair<int, int> const &b) -> bool {
            return a.second > b.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(fn)> pq(fn);
        pq.push(std::make_pair(0, 0));
        int res{0};
        while (!pq.empty() && pq.top().second <= maxMoves) {
            std::pair<int, int> node = pq.top();
            pq.pop();
            if (visited.count(node.first) > 0) {
                continue;
            }
            visited.emplace(node.first);
            ++res;
            for (auto &[no, step] : adjoints[node.first]) {
                if (node.second + 1 + step <= maxMoves) {
                    pq.push(std::make_pair(no, node.second + 1 + step));
                }
                nodesMap[encode(node.first, no, n)] = std::min(step, maxMoves - node.second);
            }
        }
        for (vector<int> &edge : edges) {
            res += std::min(edge[2], nodesMap[encode(edge[0], edge[1], n)] + nodesMap[encode(edge[1], edge[0], n)]);
        }
        return res;
    }
};