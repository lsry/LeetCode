#include <string>
using std::string;

class Solution {
public:
    int numSteps(string s) {
        int step = 0;
        for (int i = s.size() - 1;i > 0;--i) {
            ++step;
            if (s[i] == '0') {
                continue;
            }
            int j{i};
            while (j >= 0 && s[j] == '1') {
                --j;
            }
            step += i - j;
            if (j < 0) {
                break;
            }
            s[j] = '1';
            i = j + 1;
        }
        return step;
    }
};
