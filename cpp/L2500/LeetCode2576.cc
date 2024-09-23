#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int N = nums.size();
        int ans{0};
        std::sort(nums.begin(), nums.end());
        for (int i = 0, j = N / 2;i < N / 2 && j < N;++i, ++j) {
            while (j < N && 2 * nums[i] > nums[j]) {
                ++j;
            }
            if (j < N) {
                ans += 2;
            }
        }      
        return ans;
    }
};