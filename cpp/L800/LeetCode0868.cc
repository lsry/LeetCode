#include <algorithm>
class Solution {
public:
    int binaryGap(int n) {
        int distance = 0;
        int first = -1;
        for (int i{0};i < 32 && n != 0;++i, n = n >> 1) {
            if ((n & 1) == 1) {
               if (first != -1) {
                   distance = std::max(distance, i - first);
               }
               first = i;
            }
        }
        return distance;
    }
};