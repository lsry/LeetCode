#include <vector>
using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans{0};
        for (int num : nums) {
            int n1 = ans % 2 == 0 ? num : 1 - num;
            if (n1 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};