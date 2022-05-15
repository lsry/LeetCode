#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::size_t sz{nums.size()};
        vector<int> res;
        for (std::size_t i{0};i < sz;++i) {
            int num = nums[i];
            if (nums[num - 1] == num) {
                if (i != num - 1) {
                    nums[i] = -num;
                    res.push_back(num);
                }
            } else {
                nums[i] = -num;
                while (num > 0 && nums[num - 1] != num) {
                    int t = nums[num - 1];
                    nums[num - 1] = num;
                    num = t;
                }
                if (num > 0) {
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};