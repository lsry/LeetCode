#include <vector>
using std::vector;

/**
 * (n, m + 1) = (n - m) / (m + 1) * (n, m)
 */

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) {
            return 0;
        }
        for (int right{N};right > 0;--right) {
            for (int i = 0;i < right - 1;++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};

int main() {
    vector<int> a{1,2,3,4,5};
    Solution s;
    s.triangularSum(a);
}