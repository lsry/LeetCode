#include <algorithm>
#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> r;
        int nz = nums.size();
        for (int i = 0;i < nz;) {
            int j{i};
            while (j + 1 < nz && nums[j + 1] == nums[j] + 1) {
                ++j;
            }
            if (j == i) {
                r.push_back(std::to_string(nums[i]));
            } else {
                r.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[j]));
            }
            i = j + 1;
        }
        return r;
    }
};