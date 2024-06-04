#include <queue>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        std::unordered_map<int, std::queue<int>> mp;
        int N = nums.size();
        int ans{0};
        for (int i = 0;i < N;++i) {
            std::queue<int> &q = mp[nums[i]];
            while (!q.empty() && i - q.front() - q.size() > k) {
                q.pop();
            }
            ans = std::max(ans, static_cast<int>(q.size()) + 1);
            q.push(i);
        }
        return ans;
    }
};