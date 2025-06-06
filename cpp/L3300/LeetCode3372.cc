#include <algorithm>
#include <deque>
#include <vector>
using std::vector;

class Solution {
    vector<int> iterNode(vector<vector<int>> const &edges, int k) {
        int N = edges.size() + 1;
        vector<int> ans(N, 0);
        vector<vector<int>> adjoints(N, vector<int>());
        for (vector<int> const &edge : edges) {
            adjoints[edge[0]].push_back(edge[1]);
            adjoints[edge[1]].push_back(edge[0]);
        }
        std::deque<int> q;
        vector<bool> flags(N, false);
        for (int i = 0;i < N;++i) {
            q.clear();
            std::fill(flags.begin(), flags.end(), false);
            q.push_back(i);
            int count{0};
            for (int j = 0;j <= k && !q.empty();++j) {
                int sz = q.size();
                for (int x = 0;x < sz;++x) {
                    int node = q.front();
                    flags[node] = true;
                    q.pop_front();
                    for (int next : adjoints[node]) {
                        if (!flags[next]) {
                            q.push_back(next);
                        }
                    }
                }
                count += sz;
            }
            ans[i] = count;
        }
        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> tree1 = iterNode(edges1, k);
        vector<int> tree2 = iterNode(edges2, k - 1);
        int mv{*std::max_element(tree2.begin(), tree2.end())};
        for (auto it{tree1.begin()};it != tree1.end();++it) {
            *it += mv;
        }
        return tree1;
    }
};