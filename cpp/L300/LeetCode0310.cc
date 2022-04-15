#include <vector>
using std::vector;

#include <queue>
using std::queue;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> degs(n, 0);
        vector<vector<int>> adjoins(n, vector<int>());
        for (const vector<int> &edge : edges) {
            degs[edge[0]] += 1;
            degs[edge[1]] += 1;
            adjoins[edge[0]].push_back(edge[1]);
            adjoins[edge[1]].push_back(edge[0]);
        }
        queue<int> nodes;
        int remain = n;
        for (int i = 0;i < n;++i) {
            if (degs[i] == 1) {
                nodes.push(i);
            }   
        }
        while (!nodes.empty() && remain > 2) {
            int sz = nodes.size();
            remain -= sz;
            for (int i = 0;i < sz;++i) {
                int node = nodes.front();
                nodes.pop();
                for (int nx : adjoins[node]) {
                    --degs[nx]; 
                    if (degs[nx] == 1) {
                        nodes.push(nx);
                    }
                }
            }
        }
        vector<int> res;
        while (!nodes.empty()) {
            res.push_back(nodes.front());
            nodes.pop();
        }
        return res;
    }
};