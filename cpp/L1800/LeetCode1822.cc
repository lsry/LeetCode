#include <vector>
using std::vector;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool pos{true};
        for (int num : nums) {
            if (num == 0) {
                return 0;
            } else if (num < 0) {
                pos = !pos;
            }
        }
        return pos ? 1 : -1;
    }
};