#include <algorithm>
class Solution {
    /**
     * f = nb * cb + (n1 - nb) * c1 + (n2 - nb) * c2
     * f = (cb - c1 - c2) * nb + n1*c1 + n2 * c2
     */
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (costBoth - cost1 - cost2 <= 0) {
            long long r = std::max(need1, need2) * 1LL * costBoth;
            if (need1 < need2) {
                r = std::min(r, 1LL * need1 * costBoth + 1LL * (need2 - need1) * cost2);
            } else {
                r = std::min(r, 1LL * need2 * costBoth + 1LL * (need1 - need2) * cost1);
            }
            return r;
        }
        return 1LL * need1 * cost1 + 1LL * need2 * cost2;
    }
};
