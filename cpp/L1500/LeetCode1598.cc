#include <vector>
using std::vector;

#include <string>
using std::string;

#include <stack>

class Solution {
public:
    int minOperations(vector<string>& logs) {
        std::stack<string> st;
        for (string const &log : logs) {
            if (log[0] == '.') {
                if (log[1] == '.') {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
            } else {
                st.push(log);
            }
        }
        return st.size();
    }
};