#include <algorithm>
#include <stack>
#include <string>
using std::string;

class Solution {
public:
    string reverseParentheses(string s) {
        std::stack<int> lp;
        string r;
        for (int i = 0;i < s.size();++i) {
            if (s[i] == '(') {
                lp.push(r.size());
            } else if (s[i] == ')') {
                int b = lp.top();
                lp.pop();
                std::reverse(r.begin() + b, r.end());
            } else {
                r.push_back(s[i]);
            }
        }
        return r;
    }
};
