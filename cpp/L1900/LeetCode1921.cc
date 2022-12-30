#include <vector>
using std::vector;

#include <queue>

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> links(n, vector<int>());
        for (vector<int> &edge : edges) {
            links[edge[0]].push_back(edge[1]);
            links[edge[1]].push_back(edge[0]);
        }
        std::queue<int> q;
        q.push(source);
        vector<bool> flags(n, false);
        flags[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination) {
                return true;
            }
            for (int next : links[node]) {
                if (!flags[next]) {
                    flags[next] = true;
                    q.push(next);
                }
            }
        }
        return false;
    }
};