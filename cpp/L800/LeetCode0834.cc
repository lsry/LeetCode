#include <vector>
using std::vector;

#include <queue>
#include <algorithm>
#include <numeric>

class Solution {
    int zeroPath(vector<vector<int>> const &adjoints, int node, int level, 
                 vector<bool> &visits, vector<int> &zeros, vector<int> &nodes) {
        int countNode{1};
        visits[node] = true;
        zeros[node] = level;
        for (int next : adjoints[node]) {
            if (!visits[next]) {
                countNode += zeroPath(adjoints, next, level + 1, visits, zeros, nodes);
            }
        }
        nodes[node] = countNode;
        return countNode;
    }

    void countNodes(vector<vector<int>> const &adjoints, int node, int parent, vector<int> &res,
                    vector<int> const &zeros, vector<int> const &nodes, vector<bool> &visits, int n) {
        visits[node] = true;
        res[node] = res[parent] + n - 2 * nodes[node];
        for (int next : adjoints[node]) {
            if (!visits[next]) {
                countNodes(adjoints, next, node, res, zeros, nodes, visits, n);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjoints(n, vector<int>());
        for (vector<int> const &edge : edges) {
            adjoints[edge[0]].push_back(edge[1]);
            adjoints[edge[1]].push_back(edge[0]);
        }
        vector<int> zeros(n, 0);
        vector<int> nodes(n, 0);
        vector<bool> visits(n, false);
        zeroPath(adjoints, 0, 0, visits, zeros, nodes);
        vector<int> res(n, 0);
        res[0] = std::accumulate(zeros.begin(), zeros.end(), 0);
        std::fill(visits.begin(), visits.end(), false);
        visits[0] = true;
        for (int next : adjoints[0]) {
            if (!visits[next]) {
                countNodes(adjoints, next, 0, res, zeros, nodes, visits, n);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> e{{0,1},{0,2},{2,3},{2,4},{2,5}};
    s.sumOfDistancesInTree(6, e);
    return 0;
}
