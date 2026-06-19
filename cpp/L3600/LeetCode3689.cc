#include <vector>
using std::vector;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int xv{nums[0]}, iv{nums[0]};
        for (int num :nums) {
            if (num > xv) {
                xv = num;
            }
            if (num < iv) {
                iv = num;
            }
        }
        return static_cast<long long>(k) * (xv - iv);
    }
};
