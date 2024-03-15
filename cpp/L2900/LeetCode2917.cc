#include <array>
#include <vector>
using std::vector;

class Solution {
    constexpr static int N{32};
public:
    int findKOr(vector<int>& nums, int k) {
        std::array<int, N> counts{{0}};
        for (int num : nums) {
            for (int i = 0;i < N;++i) {
                if (((num >> i) & 1) == 1) {
                    counts[i] += 1;
                }
            }
        }
        int ans{0};
        for (int i = 0;i < N;++i) {
            if (counts[i] >= k) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};