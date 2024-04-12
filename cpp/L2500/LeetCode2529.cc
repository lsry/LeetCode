#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int positive{0}, negtive{0};
        int N = nums.size();
        int low = 0, high = N - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        negtive = low;
        low = 0, high = N - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        positive = N - high - 1;
        return std::max(positive, negtive);
    }
};