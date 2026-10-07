#include <string>
using std::string;

class Solution {
public:
    /**
     * consider the depth of parenthes, just drop the parenthes of depth equaling zero
     */
    string removeOuterParentheses(string s) {
        string res;
        int left = 0;
        for (char const c : s) {
            if (c == '(') {
                ++left;
                if (left > 1) {
                    res.push_back('(');
                }
            } else if (c == ')') {
                --left;
                if (left > 0) {
                    res.push_back(')');
                }
            }
        }
        return res;
    }
};
