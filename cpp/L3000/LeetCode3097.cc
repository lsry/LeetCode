#include <array>
#include <limits>
#include <vector>
using std::vector;

class Solution {
    int calc(std::array<int, 32> const &bits) {
        int ans{0};
        for (int i = 0;i < 32;++i) {
            if (bits[i] > 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
    void pushNum(std::array<int, 32> &bits, int num) {
        for (int i = 0;i < 32;++i) {
            if (((num >> i) & 1) == 1) {
                bits[i] += 1;
            }
        }
    }
    void popNum(std::array<int, 32> &bits, int num) {
        for (int i = 0;i < 32;++i) {
            if (((num >> i) & 1) == 1) {
                bits[i] -= 1;
            }
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans{std::numeric_limits<int>::max()};
        int nz = nums.size();
        std::array<int, 32> bits{0};
        for (int low{0}, high{0};high < nz;++high) {
            pushNum(bits, nums[high]);
            while (low <= high && calc(bits) >= k) {
                ans = std::min(ans, high - low + 1);
                popNum(bits, nums[low]);
                ++low;
            }
        }
        return ans == std::numeric_limits<int>::max() ? -1 : ans;
    }
};