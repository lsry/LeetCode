#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using std::vector;
#include <string>
using std::string;

struct Node {
  int index, weight, maxCon, curCon;

  Node(int index, int weight, int maxCon, int curCon):
      index(index), weight(weight), maxCon(maxCon), curCon(curCon) {}
};

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<std::pair<int, int>>> adjoins(n, vector<std::pair<int, int>>());
        for (vector<int> const &edge : edges) {
            adjoins[edge[0]].emplace_back(std::pair<int, int>(edge[1], edge[2]));
        }
        vector<vector<unsigned long long int>> dis(n, vector<unsigned long long int>(k + 1, std::numeric_limits<int>::max()));
        std::priority_queue<std::tuple<unsigned long long int, int, int>,
                         vector<std::tuple<unsigned long long int, int, int>>, std::greater<std::tuple<unsigned long long int, int, int>>> pq;
        pq.emplace(std::tuple<unsigned long long int, int, int>(0, 0, 1));
        dis[0][1] = 0;
        while (!pq.empty()) {
            auto [w, id, con] = pq.top();
            pq.pop();
            if (w > dis[id][con]) {
                continue;
            }
            if (id == n - 1) {
                return w;
            }
            for (auto const &[nid, nxw] : adjoins[id]) {
                int nextCon = labels[id] == labels[nid] ? con + 1 : 1;
                int nw = nxw + w;
                if (nextCon > k || nw >= dis[nid][nextCon]) {
                    continue;
                }
                dis[nid][nextCon] = nw;
                pq.push(std::tuple<int,int,int>(nw, nid, nextCon));
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v{{0,1,1},{1,2,1},{0,2,3}};
    s.shortestPath(3, v, "aab", 1);
}
