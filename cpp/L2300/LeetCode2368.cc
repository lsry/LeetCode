#include <queue>
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adjoints(n, vector<int>());
        for (vector<int> const &edge :edges) {
            adjoints[edge[0]].push_back(edge[1]);
            adjoints[edge[1]].push_back(edge[0]);
        }
        vector<bool> flags(n, false);
        std::unordered_set<int> baned(restricted.begin(), restricted.end());
        int ans{0};
        flags[0] = true;
        std::queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ++ans;
            for (int x : adjoints[node]) {
                if (baned.find(x) == baned.end() && !flags[x]) {
                    flags[x] = true;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};