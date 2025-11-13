#include <string>
using std::string;

class Solution {
public:
    int maxOperations(string s) {
        int ans{0};
        int sz = s.size();
        for (int one{0}, i{0};i < sz;++i) {
            if (s[i] == '1') {
                ++one;
                continue;
            }
            int j{i};
            while (j < sz && s[j] == '0') {
                ++j;
            }
            ans += one;
            i = j - 1;
        }
        return ans;
    }
};
