#include <cstdlib>
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a1 = 30.0 * hour + 0.5 * minutes;
        double a2 = 6.0 * minutes;
        double delta = std::abs(a1 - a2);
        if (delta > 180) {
            delta = 360.0 - delta;
        }
        return delta;
    }
};
