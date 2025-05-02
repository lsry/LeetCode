#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        std::unordered_set<int> st(nums.begin(), nums.end());
        int count = st.size();
        int N = nums.size();
        int ans{0};
        std::unordered_map<int, int> mp;
        for (int left{0}, right{0};right < N;++right) {
            mp[nums[right]] += 1;
            while (mp.size() == count) {
                ans += N - right;
                mp[nums[left]] -= 1;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                ++left;
            }
        }
        return ans;
    }
};