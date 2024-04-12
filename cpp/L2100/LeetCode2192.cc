#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<std::unordered_set<int>> anicents(n, std::unordered_set<int>());
        if (n <= 0) {
            return {};
        }
        vector<vector<int>> adjoins(n, vector<int>());
        vector<int> pres(n, 0);
        for (vector<int> const &edge : edges) {
            adjoins[edge[0]].push_back(edge[1]);
            pres[edge[1]] += 1;
        }
        std::queue<int> q;
        for (int i = 0;i < n;++i) {
            if (pres[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            for (int nx : adjoins[next]) {
                --pres[nx];
                if (pres[nx] == 0) {
                    q.push(nx);
                }
                anicents[nx].emplace(next);
                for (int x : anicents[next]) {
                    anicents[nx].emplace(x);
                }
            }
        }
        vector<vector<int>> r;
        for (std::unordered_set<int> const &anicent : anicents) {
            vector<int> ri(anicent.begin(), anicent.end());
            std::sort(ri.begin(), ri.end());
            r.emplace_back(ri);
        }
        return r;
    }
};