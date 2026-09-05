#include <vector>
using std::vector;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mi{0}, xi{0};
        int N = nums.size();
        for (int i = 0;i < N;++i) {
            if (nums[i] > nums[xi]) {
                xi = i;
            }
            if (nums[i] < nums[mi]) {
                mi = i;
            }
        }
        int li{std::min(mi, xi)}, hi{std::max(mi, xi)};
        return std::min(li + 1 + N - hi, std::min(hi + 1, N - li));
    }
};
