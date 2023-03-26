#include <string>
using std::string;
#include <unordered_set>
#include <queue>

class Solution {
    std::size_t sz;
    string rightRotate(string const &s, int b) {
        if (b == sz) {
            return s;
        }
        return s.substr(sz - b, b) + s.substr(0, sz - b);
    }

    void addNum(string &s, int a) {
        for (std::size_t i{1};i < sz;i += 2) {
            int n{(s[i] - '0' + a) % 10};
            s[i] = static_cast<char>('0' + n);
        }
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        sz = s.size();
        string res = s;
        std::queue<string> q;
        q.push(s);
        std::unordered_set<string> st;
        st.emplace(s);
        while (!q.empty()) {
            string ns{q.front()};
            q.pop();
            if (ns < res) {
                res = ns;
            }
            string rs = rightRotate(ns, b);
            if (st.find(rs) == st.end()) {
                q.push(rs);
                st.emplace(rs);
            }
            string rst = rs;
            do {
                addNum(rst, a);
                if (st.find(rst) == st.end()) {
                    st.emplace(rst);
                    q.push(rst);
                }
            } while (rst != rs);
        }
        return res;
    }
};