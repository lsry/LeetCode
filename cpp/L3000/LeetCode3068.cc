#include <limits>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    std::pair<long long, long long> dfs(int node, int father, vector<vector<int>> const &adjoints, vector<int> const &nums, int k) {
        long long f0 = 0, f1 = std::numeric_limits<long long>::min();
        for (int child : adjoints[node]) {
            if (child != father) {
                auto [c0, c1] = dfs(child, node, adjoints,nums, k);
                long long t0 = std::max(f0 + c0, f1 + c1);
                long long t1 = std::max(f0 + c1, f1 + c0);
                f0 = t0;
                f1 = t1;
            }
        }
        return std::pair<long long, long>(std::max(f0 + nums[node], f1 + (nums[node] ^ k)),
                                          std::max(f1 + nums[node], f0 + (nums[node] ^ k)));
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int N = nums.size();
        vector<vector<int>> adjoints(N, vector<int>());
        for (vector<int> const &edge : edges) {
            adjoints[edge[0]].emplace_back(edge[1]);
            adjoints[edge[1]].emplace_back(edge[0]);
        }      
        return dfs(0, -1, adjoints, nums, k).first;
    }
};