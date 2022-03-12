#include <string>
using std::string;

#include <algorithm>

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        bool positive = true;
        if (num < 0) {
            positive = false;
            num = -num;
        }
        string s = "";
        while (num != 0) {
            s += std::to_string(num % 7);
            num = num / 7;
        }
        std::reverse(s.begin(), s.end());
        if (!positive) {
            s = "-" + s;
        }
        return s;
    }
};