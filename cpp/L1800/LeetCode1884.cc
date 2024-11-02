#include <cmath>
class Solution {
public:
    int twoEggDrop(int n) {
        double r = (std::sqrt(1.0 + 8.0 * n) - 1) / 2.0;
        return std::ceil(r);
    }
};