#include <cmath>

class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) {
            target = -target;
        }
        int k = (int)(std::sqrt(8LL * target + 1) - 1) / 2;
        int dist = (k + 1) * k / 2;
        while (dist < target || (dist - target) % 2 != 0) {
            ++k;
            dist = (k + 1) * k / 2;
        }
        return k;
    }
};