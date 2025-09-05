#include <vector>
using std::vector;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans{0LL};
        int N = nums.size();
        for (int i = 0;i < N;) {
            if (nums[i] != 0) {
                ++i;
                continue;
            }
            int j{i};
            while (j < N && nums[j] == 0) {
                ++j;
            }
            long long len = j - i;
            ans += len * (len + 1) / 2;
            i = j;
        }
        return ans;
    }
};