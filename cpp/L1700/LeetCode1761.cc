#include <algorithm>
#include <limits>
#include <vector>
using std::vector;
#include <unordered_set>

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> adjoints(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for (vector<int> const & edge : edges) {
            int e1 = edge[0] - 1;
            int e2 = edge[1] - 1;
            adjoints[e1][e2] = true;
            adjoints[e2][e1] = true;
            degree[e1] += 1;
            degree[e2] += 1;
        }
        vector<int> nodes(n, 0);
        for (int i = 0;i < n;++i) {
            nodes[i] = i;
        }
        std::stable_sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            return degree[a] <= degree[b];
        });
        int ans{std::numeric_limits<int>::max()};
        for (int i{0};i < n;++i) {
            for (int j{i + 1};j < n;++j) {
                if (adjoints[nodes[i]][nodes[j]]) {
                    for (int k{j + 1};k < n;++k) {
                        if (adjoints[nodes[i]][nodes[k]] && adjoints[nodes[j]][nodes[k]]) {
                            int d = degree[nodes[i]] + degree[nodes[j]] + degree[nodes[k]];
                            d -= 6;
                            ans = std::min(ans, d);
                            break;
                        }
                    }
                }
            }
        }
        return ans == std::numeric_limits<int>::max() ? -1 : ans;
    }
};