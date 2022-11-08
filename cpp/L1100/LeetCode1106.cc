#include <string>
using std::string;

#include <stack>

class Solution {
public:
    bool parseBoolExpr(string expression) {
        std::stack<char> op, rs;
        for (char c : expression) {
            if (c == '!' || c == '&' || c == '|') {
                op.push(c);
            } else if (c == '(' || c == 't' || c == 'f') {
                rs.push(c);
            } else if (c == ')') {
                char c1{op.top()};
                op.pop();
                bool r{c1 == '|' ? false : true};
                if (c1 == '!') {
                    r = rs.top() == 't' ? false : true;
                    rs.pop();
                } else {
                    while (!rs.empty() && rs.top() != '(') {
                        bool rt{rs.top() == 't' ? true : false};
                        if (c1 == '|') {
                            r |= rt;
                        } else {
                            r &= rt;
                        }
                        rs.pop();
                    }
                }
                rs.pop();
                rs.push(r ? 't' : 'f');
            }
        }
        return rs.top() == 't';
    }
};
