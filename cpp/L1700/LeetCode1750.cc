#include <string>
using std::string;

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size();
        for (;i < j;++i) {
            int a = i;
            while (i + 1 < j && s[i + 1] == s[i]) {
                ++i;
            }
            int k = j;
            while (j - 1 > i && s[j - 1] == s[i]) {
                --j;
            }
            if (j == k) {
                if (i != a && i + 1 == j) {
                    return 0;
                }
                i = a - 1;
                break;
            }
        }
        return i < j ? j - i - 1 : 0;
    }
};