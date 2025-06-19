#include <cstdlib>
#include <vector>
using std::vector;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int N = nums.size();
        int ans{0};
        for (int i = 0;i < N;++i) {
            int a = nums[i];
            int b = nums[(i + 1) % N];
            ans = std::max(ans, std::abs(a - b));
        }      
        return ans;
    }
};