#include <vector>
using std::vector;
#include <algorithm>
#include <numeric>

class Solution {
    void dijkstra(int n, vector<vector<int>> &edges, vector<vector<int>> &dis, int delta, int k, 
                 std::vector<std::vector<std::pair<int, int>>> &adjoints, int destination) {
        vector<int> visited(n, false);
        while (true) {
            int x{-1};
            for (int i = 0;i < n;++i) {
                if (!visited[i] && (x < 0 || dis[i][k] < dis[x][k])) {
                    x = i;
                }
            }
            if (x == destination) {
                return;
            }
            visited[x] = true;
            for (auto &[y, no] : adjoints[x]) {
                int wt = edges[no][2];
                if (wt == -1) {
                    wt = 1;
                }
                if (k == 1 && edges[no][2] == -1) {
                    int w = delta + dis[y][0] - dis[x][1];
                    if (w > wt) {
                        wt = w;
                        edges[no][2] = wt;
                    }
                }
                dis[y][k] = std::min(dis[y][k], dis[x][k] + wt);
            }
        }
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        std::vector<std::vector<std::pair<int, int>>> adjoints(n, std::vector<std::pair<int, int>>());
        for (int i = 0;i < edges.size();++i) {
            adjoints[edges[i][0]].push_back(std::make_pair(edges[i][1], i));
            adjoints[edges[i][1]].push_back(std::make_pair(edges[i][0], i));
        }
        vector<vector<int>> dis(n, vector<int>(2, std::numeric_limits<int>::max() - 1'000'000'000));
        dis[source][0] = 0;
        dis[source][1] = 0;
        dijkstra(n, edges, dis, 0, 0, adjoints, destination);
        if (dis[destination][0] > target) {
            return {};
        }
        dijkstra(n, edges, dis, target - dis[destination][0], 1, adjoints, destination);
        if (target > dis[destination][1]) {
            return {};
        }
        for (vector<int> &edge : edges) {
            if (edge[2] == -1) {
                edge[2] = 1;
            }
        }
        return edges;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> edges{{4,1,-1}, {2,0,-1}, {0,3,-1}, {4,3,-1}};
    s.modifiedGraphEdges(5, edges, 0, 1 , 5);
    return 0;
}
