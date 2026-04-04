#include <string>
using std::string;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int one{0};
        int N = s.size();
        for (int i = 0;i < N;++i) {
            if (s[i] == '0') {
                continue;
            }
            int j{i};
            while (j < N && s[j] == '1') {
                ++j;
            }
            ++one;
            i = j - 1;
        }
        return one == 0 || one == 1;
    }
};
