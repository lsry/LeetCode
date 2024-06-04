#include <utility>
#include <vector>
using std::vector;

class Solution {
    void dfs(vector<vector<std::pair<int, int>>> const &adjoints, int root, int distance, int &count, vector<bool> &flags, int signalSpeed) {
        if (flags[root]) {
            return;
        }
        if (distance % signalSpeed == 0) {
            ++count;
        }
        flags[root] = true;
        for (auto const &[next, weight] : adjoints[root]) {
            dfs(adjoints, next, distance + weight, count, flags, signalSpeed);
        }
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int N = edges.size() + 1;
        vector<vector<std::pair<int, int>>> adjoints(N, vector<std::pair<int, int>>());
        for (vector<int> const &edge : edges) {
            adjoints[edge[0]].push_back(std::pair<int, int>(edge[1], edge[2]));
            adjoints[edge[1]].push_back(std::pair<int, int>(edge[0], edge[2]));
        }
        vector<int> res(N, 0);
        for (int i = 0;i < N;++i) {
            vector<int> substrees;
            for (auto const &[next, weight] : adjoints[i]) {
                int substree = 0;
                vector<bool> flags(N, false);
                flags[i] = true;
                dfs(adjoints, next, weight, substree, flags, signalSpeed);
                substrees.emplace_back(substree);
            }
            int L = substrees.size();
            for (int j = 0;j < L;++j) {
                for (int k = j + 1;k < L;++k) {
                    res[i] += substrees[j] * substrees[k];
                }
            }
        }
        return res;
    }
};