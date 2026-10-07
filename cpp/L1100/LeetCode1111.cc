#include <stack>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int N = seq.size();
        vector<int> ans(N, 0);
        std::stack<int> st;
        int of{0};
        for (int i = 0;i < N;++i) {
            if (seq[i] == '(') {
                ans[i] = of;
                of = 1 - of;
                st.push(i);
            } else if (seq[i] == ')') {
                int top = st.top();
                st.pop();
                ans[i] = ans[top];
                of = 1 - of;
            }
        }
        return ans;
    }
};
