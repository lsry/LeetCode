#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        bool find{false};
        map[0] = 1;
        int sum{0}, ans{0};
        for (int num : nums) {
            if (num == k) {
                find = true;
            }
            sum += num < k ? -1 : (num == k ? 0 : 1);
            if (find) {
                auto it{map.find(sum)};
                if (it != map.end()) {
                    ans += it->second;
                }
                it = map.find(sum - 1);
                if (it != map.end()) {
                    ans += it->second;
                }
            } else {
                map[sum] += 1;
            }
        }
        return ans;
    }
};