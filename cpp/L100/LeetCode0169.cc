#include <vector>
using std::vector;

class Solution {
public:
    /**
     * 摩尔投票法找绝对众数（count > n / 2)
     */
    int majorityElement(vector<int>& nums) {
        int x{-1}, count{0};
        for (int num : nums) {
            if (count == 0) {
                x = num;
                count = 1;
            } else if (x == num) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        return x;
    }
};