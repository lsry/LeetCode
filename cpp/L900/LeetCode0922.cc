#include <cstddef>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        std::size_t N{nums.size()};
        for (std::size_t eid{0}, oid{1};eid < N && oid < N;) {
            if (nums[eid] % 2 == 1) {
                while (nums[oid] % 2 == 1) {
                    oid += 2;
                }
                int x = nums[eid];
                nums[eid] = nums[oid];
                nums[oid] = x;
                eid += 2;
            } else if (nums[oid] % 2 == 0) {
                while (nums[eid] % 2 == 0) {
                    eid += 2;
                }
                int x = nums[eid];
                nums[eid] = nums[oid];
                nums[oid] = x;
                oid += 2;
            } else if (nums[eid] % 2 == 0) {
                eid += 2;
            } else if (nums[oid] % 2 == 1) {
                oid += 2;
            }
        }      
        return nums;
    }
};