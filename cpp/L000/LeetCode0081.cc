#include <vector>
using std::vector;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int low = 0, high = nums.size() - 1;low <= high;) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[low] == nums[high] && nums[low] == nums[mid]) {
                ++low;
                --high;
            } else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }      
        return false;
    }
};

int main() {
    Solution s;
    vector<int> r{1,0,1,1,1};
    s.search(r, 0);
    return 0;
}