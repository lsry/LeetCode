#include <string>
using std::string;

class Solution {
public:
    string solveEquation(string equation) {
        int coff = 0, rvalue = 0;
        bool left = true, pos = true;
        int eq = equation.size();
        for (int i = 0;i < eq;++i) {
            if (equation[i] == '-') {
                pos = false;
            } else if (equation[i] == '+') {
                pos = true;
            } else if (equation[i] == '=') {
                left = false;
                pos = true;
            } else if (equation[i] == 'x') {
                if (left) {
                    pos ? coff += 1 : coff -= 1;
                } else {
                    pos ? coff -= 1 : coff += 1;
                }
            } else {
                int num = 0;
                while (i < eq && equation[i] >= '0' && equation[i] <= '9') {
                    num = num * 10 + (equation[i] - '0');
                    ++i;
                }
                if (i < eq && equation[i] == 'x') {
                    if (left) {
                        pos ? coff += num : coff -= num;
                    } else {
                        pos ? coff -= num : coff += num;
                    }
                } else {
                    if (left) {
                        pos ? rvalue -= num : rvalue += num;
                    } else {
                        pos ? rvalue += num : rvalue -= num;
                    }
                    --i;
                }
            }
        }
        if (coff == 0) {
            return rvalue == 0 ? "Infinite solutions" : "No solution";
        }
        return "x=" + std::to_string(rvalue / coff);
    }
};