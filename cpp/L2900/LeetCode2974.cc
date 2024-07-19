#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = 0;i < N && i + 1 < N;i += 2) {
            std::swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};