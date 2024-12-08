#include <vector>
using std::vector;

class Solution {
    int count{0};
    int dfs(vector<vector<int>> const &adjoints, vector<bool> &flags, int node) {
        if (flags[node]) {
            return 0;
        }
        int nodeCount{0};
        bool good{true};
        flags[node] = true;
        int nz = adjoints[node].size();
        vector<int> childCounts;
        for (int i = 0;i < nz;++i) {
            int nextNode = adjoints[node][i];
            if (flags[nextNode]) {
                continue;
            }
            int nextNodeCount = dfs(adjoints, flags, nextNode);
            childCounts.push_back(nextNodeCount);
            nodeCount += nextNodeCount;
        }
        for (int i = 1;i < childCounts.size();++i) {
            if (childCounts[i] != childCounts[0]) {
                good = false;
                break;
            }
        }
        if (good) {
            ++count;
        }
        return nodeCount + 1;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        count = 0;
        int n = edges.size();
        vector<vector<int>> adjoints(n + 1, vector<int>());
        for (vector<int> const &edge :edges) {
            adjoints[edge[0]].push_back(edge[1]);
            adjoints[edge[1]].push_back(edge[0]);
        }
        vector<bool> flags(n + 1, false);
        dfs(adjoints, flags, 0);
        return count;
    }
};