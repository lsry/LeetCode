#include <string>
using std::string;

class Solution {
public:
    string removeStars(string s) {
        string r;
        for (char c : s) {
            if (c == '*') {
                r.pop_back();
            } else {
                r.push_back(c);
            }
        }     
        return r;
    }
};