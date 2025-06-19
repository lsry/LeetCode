#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int ans{0};
        int N = nums.size();
        for (int i = 0;i < N;) {
            ++ans;
            int j = i;
            while (j < N && nums[j] - nums[i] <= k) {
                ++j;
            }
            i = j;
        }
        return ans;
    }
};