#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        std::unordered_map<int, vector<int>> mp;
        int N = nums.size();
        for (int i = 0;i < N;++i) {
            mp[nums[i]].push_back(i);
        }
        int ans{N};
        for (auto const &[num, poses] : mp) {
            int mx = poses[0] + N - poses.back();
            for (int i = 1;i < poses.size();++i) {
                mx = std::max(mx, poses[i] - poses[i - 1]);
            }
            ans = std::min(ans, mx / 2);
        }
        return ans;
    }
};