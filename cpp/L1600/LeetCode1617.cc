#include <vector>
using std::vector;
#include <queue>

class Solution {
    int bfs(vector<vector<int>> const &adjoints, int state, int cur) {
        std::queue<int> q;
        q.push(cur);
        int st = 0;
        int d = 0;
        while (!q.empty()) {
            int qz = q.size();
            for (int x = 0;x < qz;++x) {
                int node = q.front();
                q.pop();
                st |= (1 << node);
                for (int next : adjoints[node]) {
                    int ni = 1 << next;
                    if ((ni & st) == 0 && (ni & state) != 0) {
                        q.push(next);
                    }
                }
            }
            ++d;
        }
        return st == state ? d : 0;
    }
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjoints(n, vector<int>());
        for (vector<int> const &edge : edges) {
            adjoints[edge[0] - 1].push_back(edge[1] - 1);
            adjoints[edge[1] - 1].push_back(edge[0] - 1);
        }
        vector<int> res(n - 1, 0);
        for (int i = 3;i < (1 << n);++i) {
            vector<int> vn;
            for (int j = 0;j < n;++j) {
                if (((1 << j) & i) != 0) {
                    vn.push_back(j);
                }
            }
            int d = 0;
            for (int node : vn) {
                d = std::max(d, bfs(adjoints, i, node));
            }
            if (d >= 2) {
                res[d - 2] += 1;
            }
        }
        return res;
    }
};