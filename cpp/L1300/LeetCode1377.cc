#include <vector>
using std::vector;
#include <queue>

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adjoints(n + 1, vector<int>());
        for (vector<int> const &edge : edges) {
            adjoints[edge[0]].push_back(edge[1]);
            adjoints[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n + 1, false);
        vector<std::pair<int, double>> probales(n + 1, std::pair<int, double>(100000, 0.0));
        std::queue<std::pair<int, double>> q;
        q.push(std::pair<int, double>(1, 1.0));
        int time{0};
        bool targetFlag{false};
        while (!q.empty() && time <= t && !targetFlag) {
            int qz = q.size();
            for (int i = 0;i < qz;++i) {
                auto [node, prob] = q.front();
                q.pop();
                visited[node] = true;
                probales[node].first = time;
                probales[node].second = prob;
                if (node == target) {
                    targetFlag = true;
                    break;
                }
                int count{0};
                for (int next : adjoints[node]) {
                    if (!visited[next]) {
                        ++count;
                    }
                }
                if (count == 0) {
                    continue;
                }
                for (int next : adjoints[node]) {
                    if (!visited[next]) {
                        q.push(std::pair<int, double>(next, prob / count));
                    }
                }
            }
            ++time;
        }
        if (t < probales[target].first) {
            return 0.0;
        }
        if (t == probales[target].first) {
            return probales[target].second;
        }
        for (int next : adjoints[target]) {
            if (!visited[next]) {
                return 0.0;
            }
        }
        return probales[target].second;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> edges{{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    Solution s;
    s.frogPosition(7, edges, 2, 4);
    return 0;
}
