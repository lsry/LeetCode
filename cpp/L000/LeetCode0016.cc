#include <vector>
using std::vector;
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int nz = nums.size();
        int goal{nums[0] + nums[1] + nums[2]};
        for (int i = 0;i < nz - 2;++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j{i + 1}, k{nz - 1};j < k;) {
                int next{nums[i] + nums[j] + nums[k]};
                if (next == target) {
                    return target;
                } 
                if (next > target) {
                    --k;
                } else {
                    ++j;
                }
                if (std::abs(goal - target) > std::abs(next - target)) {
                    goal = next;
                }
            }
        }
        return goal;
    }
};