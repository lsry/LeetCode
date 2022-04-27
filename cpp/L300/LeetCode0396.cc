#include <vector>
using std::vector;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, maxF = 0;
        int sz = nums.size();
        for (int i = 0;i < sz;++i) {
            sum += nums[i];
            maxF += i * nums[i];
        }
        int fi = maxF;
        for (int i = 1,lastIndex = sz - 1;i < sz;++i) {
            int curFi = fi - (sz - 1) * nums[lastIndex] + sum - nums[lastIndex];
            maxF = std::max(curFi, maxF);
            fi = curFi;
            lastIndex = (lastIndex - 1 + sz) % sz;
        }
        return maxF;
    }
};