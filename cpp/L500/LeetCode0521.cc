#include <string>
using std::string;

class Solution {
public:
    int findLUSlength(string a, string b) {
        int la = a.size(), lb = b.size();
        if (la != lb) {
            return std::max(la, lb);
        }
        for (int i = 0;i < la;++i) {
            if (a[i] != b[i]) {
                return la;
            }
        }
        return -1;
    }
};