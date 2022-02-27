#include <string>
using std::string;

#include <array>
using std::array;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        array<int, 2> n1, n2;
        find(num1, n1);
        find(num2, n2);
        int r1 = n1[0] * n2[0] - n1[1] * n2[1];
        int r2 = n1[0] * n2[1] + n1[1] * n2[0];
        return std::to_string(r1) + "+" + std::to_string(r2) + "i";
    }

private:
    void find(string &num, array<int, 2> &digit) {
        std::size_t sz = num.size();
        std::size_t i = 0;
        digit[0] = 0;
        bool flag = false;
        if (num[i] == '-') {
            flag = true;
            ++i;
        }
        while (i < sz && num[i] != '+') {
            digit[0] = digit[0] * 10 + (num[i] - '0');
            ++i;
        }
        if (flag) {
            digit[0] *= -1;
        }
        ++i;
        flag = false;
        if (num[i] == '-') {
            flag = true;
            ++i;
        }
        digit[1] = 0;
        while (i < sz && num[i] != 'i') {
            digit[1] = digit[1] * 10 + (num[i] - '0');
            ++i;
        }
        if (flag) {
            digit[1] *= -1;
        }
    }
};