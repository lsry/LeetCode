#include <vector>
using std::vector;
#include <stack>

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> st;
        std::size_t nz{pushed.size()};
        for (std::size_t i{0}, j{0};i < nz;++i) {
            st.push(pushed[i]);
            while (!st.empty() && j < nz && st.top() == popped[j]) {
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
};