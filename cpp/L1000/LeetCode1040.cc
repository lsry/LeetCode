#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        vector<int> res{0, 0};
        int sz = stones.size();
        if (sz < 3) {
            return res;
        }
        std::stable_sort(stones.begin(), stones.end());
        int e1{stones[sz - 2] - stones[0] - sz + 2}, e2{stones[sz - 1] - stones[1] - sz + 2};
        res[1] = std::max(e1, e2);
        if (e1 == 0 || e2 == 0) {
            res[0] = std::min(2, res[1]);
            return res;
        }
        int maxCount{0};
        for (int i = 0, j = 1;j < sz;++j) {
            while (i < sz && stones[j] - stones[i] + 1 > sz) {
                ++i;
            }
            maxCount = std::max(maxCount, j - i + 1);
        }
        res[0] = sz - maxCount;
        return res;
    }
};