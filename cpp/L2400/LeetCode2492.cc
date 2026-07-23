#include <limits>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        std::vector<std::vector<std::pair<int, int>>> adjoins(n, vector<std::pair<int, int>>());
        for (vector<int> const &road : roads) {
            adjoins[road[0] - 1].push_back(std::pair<int, int>(road[1] - 1, road[2]));
            adjoins[road[1] - 1].push_back(std::pair<int, int>(road[0] - 1, road[2]));
        }
        int ans{std::numeric_limits<int>::max()};
        std::queue<int> q;
        q.push(0);
        vector<int> visited(n, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;
            for (auto const &[next, distance] : adjoins[node]) {
                if (!visited[next]) {
                    ans = std::min(ans, distance);
                    q.push(next);
                }
            }
        }
        return ans;
    }
};
