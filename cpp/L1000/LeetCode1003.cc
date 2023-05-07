#include <string>
using std::string;

#include <vector>

class Solution {
public:
    bool isValid(string s) {
        std::vector<char> st;
        for (char c : s) {
            if (c == 'c') {
                if (st.size() < 2 || st[st.size() - 1] != 'b' || st[st.size() - 2] != 'a') {
                    return false;
                }
                st.pop_back();
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st.empty();
    }
};