#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        for (int i = 0;i <= 1000;++i) {
            int x = i | (i + 1);
            if (!mp.contains(x)) {
                mp[x] = i;
            }
        }
        vector<int> ans(nums.size(), -1);
        for (int i = 0;i < nums.size();++i) {
            auto it{mp.find(nums[i])};
            if (it != mp.end()) {
                ans[i] = it->second;
            }
        }
        return ans;
    }
};
