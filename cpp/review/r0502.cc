#include <string>
using std::string;

class Solution {
public:
    string printBin(double num) {
        string res{"0."};
        int i = 0;
        while (i < 32 && num > 1e-6) {
            num *= 2;
            if (num >= 1.0) {
                res.push_back('1');
                num -= 1.0;
            } else {
                res.push_back('0');
            }
            ++i;
        }
        return i < 32 ? res : "ERROR";
    }
};