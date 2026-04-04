#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        int deleted{N};
        for (int low{0}, high{0};high < N;++high) {
            while (low < high && 1LL * k * nums[low] < nums[high]) {
                ++low;
            }
            deleted = std::min(deleted, N - (high - low + 1));
        }
        return deleted;
    }
};
