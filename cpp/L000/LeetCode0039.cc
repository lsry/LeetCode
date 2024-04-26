#include <vector>
using std::vector;

class Solution {
    void trace(vector<vector<int>> &alls, vector<int> &paths, int curSum, int target, vector<int>& candidates, int index) {
        if (curSum == target) {
            alls.push_back(paths);
            return;
        }
        for (int i = index;i < candidates.size();++i) {
            int cand = candidates[i];
            if (cand + curSum <= target) {
                paths.push_back(cand);
                trace(alls, paths, cand + curSum, target, candidates, i);
                paths.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> paths;
        trace(res, paths, 0, target, candidates, 0);
        return res;
    }
};