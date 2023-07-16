#include <string>
using std::string;
#include <algorithm>
#include <array>

class Solution {
    constexpr static std::array<char, 10> chs{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
public:
    string addStrings(string num1, string num2) {
        int carry{0};
        string r;
        for (int n1 = num1.size() - 1, n2 = num2.size() - 1;n1 >= 0 || n2 >= 0 || carry != 0;) {
            if (n1 >= 0) {
                carry += num1[n1] - '0';
                --n1;
            }
            if (n2 >= 0) {
                carry += num2[n2] - '0';
                --n2;
            }
            r.push_back(chs[carry % 10]);
            carry /= 10;
        }
        std::reverse(r.begin(), r.end());
        return r;
    }
};