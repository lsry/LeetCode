#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        for (int i = 0;i < nums.size();++i) {
            auto it{mp.find(nums[i])};
            if (it != mp.end() && i - it->second <= k) {
                return true;
            } else {
                mp[nums[i]] = i;
            }
        }      
        return false;
    }
};