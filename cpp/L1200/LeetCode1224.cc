#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        std::unordered_map<int, int> cnt, sum;
        int maxCnt{0}, maxSum{0};
        std::size_t nz{nums.size()};
        int res = 0;
        for (std::size_t i{0};i < nz;++i) {
            int t = nums[i];
            int len = i + 1;
            cnt[t] += 1;
            int f = cnt[t];
            maxCnt = std::max(f, maxCnt);
            sum[f] += 1;
            sum[f - 1] -= 1;
            if (maxCnt == 1 || maxCnt * sum[maxCnt] + 1 == len
                || (maxCnt - 1) * (sum[maxCnt - 1] + 1) + 1 == len) {
                res = len;
            }
        }
        return res;
    }
};