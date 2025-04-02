#include <vector>
using std::vector;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int N = nums.size();
        if (N < 3) {
            return 0LL;
        }
        vector<int> suffix(N, 0);
        int xv{0};
        for (int i = N - 1;i >= 0;--i) {
            suffix[i] = xv;
            xv = std::max(xv, nums[i]);
        }
        long long int ans{0L};
        long long int bx{nums[0]};
        for (int i = 1;i < N - 1;++i) {
            long long int v = (bx - nums[i]) * 1LL * suffix[i];
            ans = std::max(v, ans);
            bx = std::max(bx, nums[i] * 1LL);
        }
        return ans;
    }
};