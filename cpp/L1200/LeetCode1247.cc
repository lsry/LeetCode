#include <string>
using std::string;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x1{0}, y1{0}, x2{0}, y2{0};
        std::size_t sz{s1.size()};
        for (std::size_t i{0};i < sz;++i) {
            if (s1[i] != s2[i]) {
                s1[i] == 'x' ? ++x1 : ++y1;
                s2[i] == 'x' ? ++x2 : ++y2;
            }
        }
        int swaps{0};
        int t = 0;
        if (x1 < y2) {
            t = x1 % 2 == 0 ? x1 : x1 -  1;
        } else {
            t = y2 % 2 == 0 ? y2 : y2 - 1;
        }
        x1 -= t;
        y2 -= t;
        swaps += t / 2;
        if (x2 < y1) {
            t = x2 % 2 == 0 ? x2 : x2 - 1;
        } else {
            t = y1 % 2 == 0 ? y1 : y1 - 1;
        }
        x2 -= t;
        y1 -= t;
        swaps += t / 2;
        if ((x1 + x2) % 2 != 0 || (y1 + y2) % 2 != 0) {
            return -1;
        }
        return swaps + (x2 != 0 ? 2 : 0);
    }
};