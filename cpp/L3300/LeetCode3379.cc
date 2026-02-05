#include <vector>
using std::vector;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> r(N, 0);
        for (int i = 0;i < N;++i) {
            r[i] = nums[(i + (nums[i] % N) + N) % N];
        }
        return r;
    }
};
