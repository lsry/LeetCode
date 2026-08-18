#include <queue>
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> nexts(n, vector<int>());
        for (vector<int> const &in : invocations) {
            nexts[in[0]].push_back(in[1]);
        }
        std::unordered_set<int> baned;
        vector<bool> visited(n, false);
        std::queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            baned.insert(cur);
            for (int next : nexts[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        bool isInvocated{false};
        for (vector<int> const &in : invocations) {
            if (!baned.contains(in[0]) && baned.contains(in[1])) {
                isInvocated = true;
                break;
            }
        }
        vector<int> ans{};
        ans.reserve(n);
        for (int i = 0;i < n;++i) {
            if (isInvocated) {
                ans.push_back(i);
            } else if (!baned.contains(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
