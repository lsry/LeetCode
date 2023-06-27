#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        int t = (n * n + n) / 2;
        int r = static_cast<int>(std::sqrt(t));
        if (r * r == t) {
            return r;
        }      
        return -1;
    }
};