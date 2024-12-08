#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for (string const &command : commands) {
            if (command == "UP") {
                --x;
            } else if (command == "RIGHT") {
                ++y;
            } else if (command == "LEFT") {
                --y;
            } else if (command == "DOWN") {
                ++x;
            }
        }
        return x * n + y;
    }
};