#include <unordered_set>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    int dfs(vector<int> &ans, vector<std::unordered_set<int>> &gens, int node, vector<int>& parents, vector<vector<int>> const &children, vector<int>& nums) {
        gens[node].insert(nums[node]);
        for (int child : children[node]) {
            int childGen = dfs(ans, gens, child, parents, children, nums);
            ans[node] = std::max(childGen, ans[node]);
            if (gens[node].size() < gens[child].size()) {
                std::swap(gens[node], gens[child]);
            }
            gens[node].merge(gens[child]);
        }
        while (gens[node].find(ans[node]) != gens[node].end()) {
            ++ans[node];
        }
        return ans[node];
    }
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<vector<int>> children(n, vector<int>());
        for (int i = 0;i < n;++i) {
            if (parents[i] != -1) {
                children[parents[i]].push_back(i);
            }
        }
        vector<int> ans(n, 1);
        vector<std::unordered_set<int>> gens(n, std::unordered_set<int>());
        dfs(ans, gens, 0, parents, children, nums);
        return ans;
    }
};