#include <vector>
using std::vector;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> flags(101, false);
        for (int num : nums) {
            flags[num] = true;
        }
        int step{0}, num{0};
        for (int i = 1;i < 101;++i) {
            if (i == num || !flags[i]) {
                continue;
            }
            if (i > num) {
                num = i;
                ++step;
            }
        }
        return step;
    }
};