#include <algorithm>
#include <cstdlib>
#include <vector>
using std::vector;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            return std::abs(a) > std::abs(b);
        });
        int N = nums.size();
        long long int ans{0LL};
        for (int i = 0;i < N;++i) {
            if (i * 2 < N) {
                ans += 1LL * nums[i] * nums[i];
            } else {
                ans -= 1LL * nums[i] * nums[i];
            }
        }
        return ans;
    }
};
