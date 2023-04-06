#include <string>
using std::string;
#include <algorithm>

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        string res;
        while (n != 1) {
            int t = n > 0 ? n : -n;
            if (t % 2 == 0) {
                res.push_back('0');
            } else {
                res.push_back('1');
                n -= 1;
            }
            n = n / (-2);
        }
        res.push_back('1');
        std::reverse(res.begin(), res.end());
        return res;
    }
};