#include <string>
using std::string;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int left = 0;
        for (char const c : s) {
            if (c == '(') {
                ++left;
                if (left > 1) {
                    res += "(";
                }
            } else if (c == ')') {
                --left;
                if (left > 0) {
                    res += ")";
                }
            }
        }
        return res;
    }
};