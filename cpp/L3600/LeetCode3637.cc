#include <vector>
using std::vector;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int N = nums.size();
        int p{0};
        while (p + 1 < N && nums[p + 1] > nums[p]) {
            ++p;
        }
        if (p + 1 >= N) {
            return false;
        }
        int q{p};
        while (q < N && q + 1 < N && nums[q + 1] < nums[q]) {
            ++q;
        }
        if (q + 1 >= N) {
            return false;
        }
        int t{q + 1};
        while (t < N && nums[t] > nums[t - 1]) {
            ++t;
        }
        return p > 0 && q > p && t >= N;
    }
};
