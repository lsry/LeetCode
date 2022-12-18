#include <vector>
using std::vector;
#include <numeric>

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> g, sums;
        sums.push_back(0);
        std::size_t nz{nums.size()};
        for (std::size_t i{0};i < nz;++i) {
            if (nums[i] == 1) {
                g.push_back(i - g.size());
                sums.push_back(sums.back() + g.back());
            }
        }
        int m = g.size(), res = std::numeric_limits<int>::max();
        for (int i = 0;i <= m - k;++i) {
            int mid = i + k / 2;
            int s = g[mid] * (1 - k % 2) + sums[i + k] - sums[mid + 1] - (sums[mid] - sums[i]);
            res = std::min(res, s);
        }
        return res;
    }
};