#include <utility>
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <stack>

class SolutionOld {
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

class Solution {
    std::pair<int, int> S(string const &s, int ix) {
        auto [as, ai] = A(s, ix);
        auto [bs, bi] = B(s, ai);
        return std::pair<int, int>(as + bs, bi);
    }
    std::pair<int, int> A(string const &s, int ix) {
        if (ix >= s.size() || s[ix] == ')') {
            return std::pair<int, int>(0, ix);
        }
        auto [score, nix] = S(s, ix + 1);
        return std::pair<int, int>(score == 0 ? 1 : 2 * score, nix + 1);
    }
    std::pair<int, int> B(string const &s, int ix) {
        if (ix >= s.size() || s[ix] == ')') {
            return std::pair<int, int>(0, ix);
        }
        return S(s, ix);
    }
public:
    int scoreOfParentheses(string s) {
        auto [a, b] = S(s, 0);
        return a;
    }
};
