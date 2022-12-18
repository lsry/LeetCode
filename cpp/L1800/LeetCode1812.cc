#include <string>
using std::string;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0] - 'a';
        int b = coordinates[1] - '1';
        return (a % 2 == 0 && b % 2 != 0) || (a % 2 != 0 && b % 2 == 0);
    }
};