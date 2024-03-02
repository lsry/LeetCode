#include <vector>
using std::vector;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }
        int N = nums.size();
        vector<bool> flags(N + 1, false);
        flags[0] = true;
        for (int i = 1;i <= N;++i) {
            if (i < N && nums[i - 1] == nums[i]) {
                flags[i + 1] = flags[i + 1] | flags[i - 1];
            }
            if (i < N && i + 1 < N) {
                if ((nums[i - 1] == nums[i] && nums[i] == nums[i + 1]) 
                  || (nums[i - 1] + 1 == nums[i] && nums[i] + 1 == nums[i + 1])) {
                    flags[i + 2] = flags[i + 2] | flags[i - 1];
                }
            }
        }
        return flags[N];
    }
};