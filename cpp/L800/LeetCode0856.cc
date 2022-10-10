#include <vector>
using std::vector;

#include <string>
using std::string;

#include <stack>

class Solution {
private:
    int trace(string const &s, int f, int e, vector<int> const &pos) {
        if (f >= e) {
            return 0;
        }
        int score = 0;
        for (int i = f;i <= e;++i) {
            if (s[i] == '(') {
                int t = trace(s, i + 1, pos[i] - 1, pos);
                score += t == 0 ? 1 : 2 * t;
                i = pos[i];
            }
        }
        return score;
    }
public:
    int scoreOfParentheses(string s) {
        int sz = s.size();
        vector<int> pos(sz, -1);
        std::stack<int> st;
        for (int i = 0;i < sz;++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int t = st.top();
                st.pop();
                pos[t] = i;
            }
        }
        return trace(s, 0, sz - 1, pos);
    }
};