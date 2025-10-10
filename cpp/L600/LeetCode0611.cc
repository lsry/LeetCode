#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int ans{0};
        for (auto it{nums.begin()};it != nums.end();++it) {
            for (auto jt{it + 1};jt != nums.end();++jt) {
                auto kt{std::lower_bound(jt + 1, nums.end(), *it + *jt)};
                ans += std::distance(jt + 1, kt);
            }
        }
        return ans;
    }
};