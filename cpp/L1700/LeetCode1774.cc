#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int m = *std::min_element(baseCosts.begin(), baseCosts.end());
        if (m >= target) {
            return m;
        }
        int len = 2 * target + 1 - m;
        vector<bool> costs(len, false);
        costs[0] = true;
        for (int tc : toppingCosts) {
            for (int i = len - tc;i >= 0;--i) {
                if (costs[i]) {
                    for (int k = 1;k <= 2 && i + k * tc <= len;++k) {
                        costs[i + k * tc] = true;
                    }
                }
            }
        }
        int res{-1};
        for (int bc : baseCosts) {
            for (int i = len;i - bc >= 0;--i) {
                if (costs[i - bc]) {
                    if (res == -1) {
                        res = i;
                    } else if (std::abs(target - i) < std::abs(res - target)) {
                        res = i;
                    } else if (std::abs(target - i) == std::abs(res - target) && i < res) {
                        res = i;
                    }
                }
            }
        }
        return res;
    }
};
