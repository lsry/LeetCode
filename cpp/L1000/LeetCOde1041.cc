#include <string>
using std::string;

class Solution {
    void nextStep(int &x, int &y, int dir) {
        switch (dir)
        {
        case 0:
            y += 1;
            break;
        case 1: 
            x += 1;
            break;
        case 2:
            y -= 1;
            break;
        default:
            x -= 1;
        }
    }
public:
    bool isRobotBounded(string instructions) {
        int x{0}, y{0}, d{0};
        for (char const c : instructions) {
            if (c == 'G') {
                nextStep(x, y, d);
            } else if (c == 'L') {
                d = (d + 3) % 4;
            } else {
                d = (d + 1) % 4;
            }
        }
        return x == 0 && y == 0 || d != 0;
    }
};