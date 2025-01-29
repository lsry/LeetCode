#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    void dfs(vector<int> const &candidates, vector<vector<int>> &results, vector<int> &path, int index, int sum, int target) {
        if (sum == target) {
            results.push_back(vector<int>(path.begin(), path.end()));
        } else if (sum > target || index >= candidates.size()) {
            return;
        }  else {
            for (int i = index;i < candidates.size();++i) {
                if (i > index && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                path.emplace_back(candidates[i]);
                dfs(candidates, results, path, i + 1, sum + candidates[i], target);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> path;
        dfs(candidates, results, path, 0, 0, target);
        return results;
    }
};