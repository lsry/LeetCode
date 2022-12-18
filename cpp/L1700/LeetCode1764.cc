#include <vector>
using std::vector;

class Solution {
    bool check(vector<int> const &group, vector<int> const &nums, std::size_t ni) {
        if (nums.size() - ni < group.size()) {
            return false;
        }
        for (std::size_t i{0};i < group.size();++i) {
            if (group[i] != nums[ni + i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        std::size_t nz{nums.size()}, ni{0};
        for (vector<int> const &group : groups) {
            bool flag = false;
            for (;ni < nz;++ni) {
                if (group[0] == nums[ni] && check(group, nums, ni)) {
                    flag = true;
                    ni += group.size();
                    break;
                }
            }
            if (!flag) {
                return false;
            }
        }
        return true;
    }
};