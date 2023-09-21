#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;
#include <queue>

class Solution {
    bool check(vector<int> const &nums, int k, int x) {
        bool visit{false};
        int count{0};
        for (int num : nums) {
            if (num > x || visit) {
                visit = false;
            } else {
                ++count;
                visit = true;
            }
        }
        return count >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *std::min_element(nums.begin(), nums.end());
        int high = *std::max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};

int main() {
    Solution s;
    vector<int> v{2,3,5,9};
    s.minCapability(v, 2);
}