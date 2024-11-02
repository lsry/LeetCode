#include <vector>
using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        int ans{0};
        for (int i = 0;i < N;++i) {
            if (nums[i] == 1) {
                continue;
            } else if (i + 2 >= N) {
                return -1;
            }
            ++ans;
            nums[i] = 1;
            nums[i + 1] = 1 - nums[i + 1];
            nums[i + 2] = 1 - nums[i + 2];
        }
        return ans;
    }
};