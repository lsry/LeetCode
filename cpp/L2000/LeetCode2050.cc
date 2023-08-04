#include <vector>
using std::vector;
#include <unordered_set>
#include <queue>

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> nexts(n, vector<int>());
        vector<std::unordered_set<int>> pres(n, std::unordered_set<int>());
        for (vector<int> const &r : relations) {
            nexts[r[0] - 1].push_back(r[1] - 1);
            pres[r[1] - 1].emplace(r[0] - 1);
        }
        vector<int> starts(n, 0);
        std::queue<int> q;
        for (int i = 0;i < n;++i) {
            if (pres[i].empty()) {
                q.push(i);
            }
        }
        int ans{0};
        while (!q.empty()) {
            int cid{q.front()};
            q.pop();
            ans = std::max(ans, starts[cid] + time[cid]);
            for (int nid : nexts[cid]) {
                starts[nid] = std::max(starts[nid], starts[cid] + time[cid]);
                pres[nid].erase(cid);
                if (pres[nid].empty()) {
                    q.push(nid);
                }
            }
        }
        return ans;
    }
};