#include <string>
using std::string;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one{0}, zero{0};
        for (char const c : s) {
            if (c == '0') {
                ++zero;
            } else {
                ++one;
            }
        }
        if (one == 0) {
            return s;
        } 
        return string(one - 1, '1') + string(zero, '0') + '1';
    }
};