#include <queue>
#include <vector>
using std::vector;

class Solution {
    vector<bool> shaderNode(vector<vector<int>> const &edges) {
        int N = edges.size() + 1;
        vector<bool> colors(N, false);
        vector<vector<int>> adjoints(N, vector<int>());
        for (vector<int> const &edge : edges) {
            adjoints[edge[0]].push_back(edge[1]);
            adjoints[edge[1]].push_back(edge[0]);
        }
        std::queue<int> q;
        q.push(0);
        bool color{false};
        vector<bool> flags(N, false);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0;i < sz;++i) {
                int node = q.front();
                q.pop();
                colors[node] = color;
                flags[node] = true;
                for (int next : adjoints[node]) {
                    if (!flags[next]) {
                        q.push(next);
                    }
                }
            }
            color = !color;
        }
        return colors;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<bool> color1 = shaderNode(edges1);
        vector<bool> color2 = shaderNode(edges2);
        int even1{0}, odd1{0};
        int even2{0}, odd2{0};
        for (bool f : color1) {
            if (f) {
                ++odd1;
            } else {
                ++even1;
            }
        }
        for (bool f : color2) {
            if (f) {
                ++odd2;
            } else {
                ++even2;
            }
        }
        vector<int> ans(edges1.size() + 1, 0);
        for (int i = 0;i < color1.size();++i) {
            if (color1[i]) {
                ans[i] = odd1 + std::max(odd2, even2);
            } else {
                ans[i] = even1 + std::max(odd2, even2);
            }
        }
        return ans;
    }
};