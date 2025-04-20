#include <vector>
using std::vector;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int N = nums.size();
        int ans{0};
        for (int i = 1;i < (1 << N);++i) {
            int sum{0};
            for (int j = 0;j < N;++j) {
                if (((i >> j) & 1) == 1) {
                    sum ^= nums[j];
                }
            }
            ans += sum;
        }      
        return ans;
    }
};