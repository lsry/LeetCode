#include <vector>
using std::vector;
#include <iostream>

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        std::size_t nz{nums.size()};
        int a = 0, b = 0;
        for (std::size_t i{0};i < nz;++i) {
            int num = nums[i];
            if (num == 0 || num == i + 1) {
                continue;
            }
            nums[i] = 0;
            if (num > nz) {
                if (a != 0) {
                    b = num;
                } else {
                    a = num;
                }
            }
            while (num <= nz && num != 0 && num != nums[num - 1]) {
                int nid = num - 1;
                int nNum = nums[nid];
                nums[nid] = num;
                num = nNum;
            }
        }
        int j = 1;
        vector<int> res;
        for (;j <= nz;++j) {
            if (nums[j - 1] == 0) {
                res.push_back(j);
            }
        }
        while (res.size() < 2) {
            if (j == a || j == b) {
                ++j;
                continue;
            }
            res.push_back(j++);
        }
        return res;
    }
};