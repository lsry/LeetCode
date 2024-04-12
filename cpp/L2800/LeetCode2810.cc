#include <algorithm>
#include <string>
using std::string;

class Solution {
public:
    string finalString(string s) {
        string r;
        for (char const c : s) {
            if (c == 'i') {
                std::reverse(r.begin(), r.end());
            } else {
                r.push_back(c);
            }
        }
        return r;
    }
};