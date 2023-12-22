#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<std::pair<int, int>>> adjoints(n, vector<std::pair<int, int>>());
        for (vector<int> const &conn : connections) {
            adjoints[conn[0]].push_back(std::pair<int, int>(conn[1], conn[0]));
            adjoints[conn[1]].push_back(std::pair<int, int>(conn[0], conn[0]));
        }
        int ans{0};
        std::queue<std::pair<int, bool>> q;
        q.push({0, false});
        vector<bool> flags(n, false);
        while (!q.empty()) {
            auto [node, f] = q.front();
            q.pop();
            if (flags[node]) {
                continue;
            }
            flags[node] = true;
            if (f) {
                ++ans;
            }
            for (auto const &[next, start] : adjoints[node]) {
                if (flags[next]) {
                    continue;
                }
                q.push(std::pair<int, bool>(next, start != next));
            }
        }
        return ans;
    }
};