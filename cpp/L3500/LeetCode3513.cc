#include <vector>
using std::vector;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int N = nums.size();
        if (N < 3) {
            return N;
        }
        int ans{0};
        while (N > 0) {
            ++ans;
            N = N >> 1;
        }
        return 1 << ans;
    }
};
