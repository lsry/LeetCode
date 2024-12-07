#include <queue>
#include <vector>
using std::vector;

class Solution {
    int getLength(vector<vector<int>> const &adjoints) {
        int ans{0};
        std::queue<int> q;
        q.push(0);
        vector<bool> flags(adjoints.size(), false);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0;i < len;++i) {
                int t = q.front();
                q.pop();
                if (t == adjoints.size() - 1) {
                    return ans;
                }
                flags[t] = true;
                for (int x : adjoints[t]) {
                    if (flags[x]) {
                        continue;
                    } else {
                        q.push(x);
                    }
                }
            }
            ++ans;
        }
        return ans;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adjoints(n, vector<int>());
        for (int i = 0;i < n - 1;++i) {
            adjoints[i].push_back(i + 1);
        }
        vector<int> ans;
        for (vector<int> const &q : queries) {
            adjoints[q[0]].push_back(q[1]);
            int x = getLength(adjoints);
            ans.push_back(x);
        }
        return ans;
    }
};