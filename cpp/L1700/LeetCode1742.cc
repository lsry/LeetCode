#include <array>

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int maxCount{0};
        std::array<int, 50> counts{{0}};
        for (int i{lowLimit};i <= highLimit;++i) {
            int num{i};
            int id{0};
            while (num != 0) {
                id += num % 10;
                num /= 10;
            }
            counts[id] += 1;
            maxCount = std::max(maxCount, counts[id]);
        }
        return maxCount;
    }
};