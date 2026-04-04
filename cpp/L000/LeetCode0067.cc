#include <algorithm>
#include <string>
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        auto ai{a.rbegin()}, bi{b.rbegin()};
        string r;
        int carry = 0;
        while (ai != a.rend() || bi != b.rend()) {
            int tx = 0;
            if (ai == a.rend()) {
                tx = (*bi - '0');
                ++bi;
            } else if (bi == b.rend()) {
                tx = (*ai - '0');
                ++ai;
            } else {
                tx = (*bi - '0') + (*ai - '0');
                ++ai;
                ++bi;
            }
            tx = tx + carry;
            r.push_back(tx % 2 == 0 ? '0' : '1');
            carry = tx / 2;
        }
        if (carry != 0) {
            r.push_back('1');
        }
        std::reverse(r.begin(), r.end());
        return r;
    }
};
