#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    void dfs(vector<int> const &nums, vector<vector<int>> &result, vector<int> &path, int id) {
        result.push_back(vector<int>(path));
        for (int i{id};i < nums.size();++i) {
            if (i > id && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, result, path, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        std::sort(nums.begin(), nums.end());
        dfs(nums, result, path, 0);
        return result;
    }
};