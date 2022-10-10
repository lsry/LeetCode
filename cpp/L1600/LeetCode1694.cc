#include <string>
using std::string;

class Solution {
public:
    string reformatNumber(string number) {
        int i = -1, j = 0;
        int nz = number.size();
        for (;j < nz;++j) {
            if (number[j] >= '0' && number[j] <= '9') {
                ++i;
                number[i] = number[j];
            }
        }
        nz = i + 1;
        string res = "";
        for (i = 0;i < nz;++i) {
            res.push_back(number[i]);
            if (i > 0 && (i + 1) % 3 == 0) {
                res.push_back('-');
            }
        }
        int rn = res.size();
        if (nz % 3 == 1 && rn - 2 >= 0 && rn - 3 >= 0) {
            char c = res[rn - 2];
            res[rn - 2] = res[rn - 3];
            res[rn - 3] = c;
        }
        if (nz % 3 == 0) {
            res.pop_back();
        }
        return res;
    }
};