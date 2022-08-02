#include <string>
using std::string;

#include <array>

class Solution {
    int gcd(int up, int down) {
        if (down > up) {
            return gcd(down, up);
        }
        return down == 0 ? up : gcd(down, up % down);
    }

public:
    string fractionAddition(string expression) {
        std::array<int, 2> head{{0, 1}};
        std::size_t ez{expression.size()};
        bool positive = true;
        std::array<int, 2> tmp{{0, 0}};
        int ti = 0;
       for (std::size_t index{0}; index <= ez;++index) {
            if (index == ez || expression[index] == '+' || expression[index] == '-') {
                if (tmp[1] != 0) {
                    int denominator = head[1] * tmp[1];
                    int m1 = head[0] * tmp[1], m2 = tmp[0] * head[1];
                    int molecule = positive ? m1 + m2 : m1 - m2;
                    int gcdNum = gcd(std::abs(molecule), std::abs(denominator));
                    if (molecule == 0) {
                        head = {0, 1};
                    } else if (gcdNum == 1) {
                        head = {molecule, denominator};
                    } else {
                        head = {molecule / gcdNum, denominator / gcdNum};
                    }
                    tmp = {0, 0};
                    ti = (ti + 1) % 2;
                }
                if (index < ez) {
                    positive = expression[index] == '+';
                }
            } else if (expression[index] == '/') {
                ti = (ti + 1) % 2;
            } else {
                tmp[ti] = tmp[ti] * 10 + (expression[index] - '0');
            }
        }
        return string("") + std::to_string(head[0]) + "/" + std::to_string(head[1]); 
    }
};