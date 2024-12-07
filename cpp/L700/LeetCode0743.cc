#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<std::pair<int, int>>> adjoints(n, vector<std::pair<int, int>>());
        for (vector<int> const &t : times) {
            adjoints[t[0] - 1].emplace_back(std::pair<int, int>(t[1] - 1, t[2]));
        }
        vector<int> flags(n, -1);
        std::queue<std::pair<int, int>> q;
        q.push(std::pair<int, int>(k - 1, 0));
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0;i < sz;++i) {
                auto [v, t] = q.front();
                q.pop();
                flags[v] = flags[v] == -1 ? t : std::min(t, flags[v]);
                for (std::pair<int, int> const &adjoint : adjoints[v]) {
                    if (flags[adjoint.first] == -1 || flags[adjoint.first] > adjoint.second + t) {
                        q.push(std::pair<int, int>(adjoint.first, adjoint.second + t));
                    }
                }
            }
        }
        int totalTime{0};
        for (int x : flags) {
            if (x == -1) {
                return -1;
            }
            totalTime = std::max(totalTime, x);
        }
        return totalTime;
    }
};