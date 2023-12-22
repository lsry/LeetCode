#include <vector>
using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        int low = 0, high = sz;
        while (low < high) {
            int mid = (low + high) / 2;
            if ((mid - 1 < 0 || nums[mid - 1] < nums[mid]) && (mid + 1 >= sz || nums[mid +  1] < nums[mid])) {
                return mid;
            }
            if (mid - 1 >= 0 && nums[mid - 1] >= nums[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};