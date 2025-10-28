#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum{std::accumulate(nums.begin(), nums.end(), 0)};
        int ans{0};
        for (int lv{0},i{0};i < nums.size();++i) {
            lv += nums[i];
            if (nums[i] != 0) {
                continue;
            }
            if (lv == sum - lv) {
                ans += 2;
            } else if (lv + 1 == sum - lv || lv - 1 == sum - lv) {
                ans += 1;
            }
        }
        return ans;
    }
};
