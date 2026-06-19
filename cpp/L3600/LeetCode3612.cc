#include <algorithm>
#include <string>
using std::string;

class Solution {
public:
    string processStr(string s) {
       string r;
       for (char c : s) {
           if (c == '*') {
               if (!r.empty()) {
                   r.pop_back();
               }
           } else if (c == '#') {
               r = r + r;
           } else if (c == '%') {
               std::reverse(r.begin(), r.end());
           } else {
               r.push_back(c);
           }
       }
       return r;
    }
};
