#include <algorithm>
#include <iterator>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int ans{0};
        int lastNum{std::numeric_limits<int>::min()}, lastCount{0};
        for (auto it{nums.begin()};it != nums.end();) {
            auto jt{it};
            while (jt != nums.end() && *it == *jt) {
                ++jt;
            }
            int count = std::distance(it, jt);
            if (lastCount > 0 && lastNum + 1 == *it) {
                ans = std::max(ans, lastCount + count);
            }
            lastCount = count;
            lastNum = *it;
            it = jt;
        }    
        return ans;  
    }
};