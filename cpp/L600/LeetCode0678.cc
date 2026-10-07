#include <stack>
#include <string>
using std::string;

class Solution {
public:
    bool checkValidString(string s) {
        std::stack<int> lefts, stars;
        int N = s.size();
        for (int i = 0;i < N;++i) {
            if (s[i] == '(') {
                lefts.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            } else if (s[i] == ')') {
                if (!lefts.empty()) {
                    lefts.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }
            }
        }
        while (!lefts.empty()) {
            if (!stars.empty() && stars.top() > lefts.top()) {
                lefts.pop();
                stars.pop();
            } else {
                return false;
            }
        }
        return lefts.empty();
    }
};
