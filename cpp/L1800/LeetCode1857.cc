#include <algorithm>
#include <queue>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();
        vector<int> inNodes(N, 0);
        vector<vector<int>> adjoints(N, vector<int>());
        for (vector<int> const &edge : edges) {
            inNodes[edge[1]] += 1;
            adjoints[edge[0]].emplace_back(edge[1]);
        }
        int ans{0};
        vector<vector<int>> dp(N, vector<int>(26, 0));
        std::queue<int> q;
        for (int i = 0;i < N;++i) {
            if (inNodes[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            dp[node][colors[node] - 'a'] ++;
            for (int next : adjoints[node]) {
                for (int i = 0;i < 26;++i) {
                    dp[next][i] = std::max(dp[next][i], dp[node][i]);
                }
                --inNodes[next];
                if (inNodes[next] == 0) {
                    q.push(next);
                }
            }
        }
        for (int inNode : inNodes) {
            if (inNode != 0) {
                return -1;
            }
        }
        for (int i = 0;i < N;++i) {
            for (int j = 0;j < 26;++j) {
                ans = std::max(ans, dp[i][j]);
            }
        }
        return ans == 0 ? -1 : ans;
    }
};