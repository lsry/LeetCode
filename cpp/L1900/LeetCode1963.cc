#include <stack>
#include <string>
using std::string;

class Solution {
public:
    int minSwaps(string s) {
        std::stack<int> st;
        int N = s.size();
        int ans{0};
        for (int i = 0, j= N - 1;i < N;++i) {
            if (s[i] == '[') {
                st.push(i);
            } else if (!st.empty()) {
                st.pop();
            } else {
                while (j > i && s[j] == ']') {
                    --j;
                }
                ++ans;
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                st.push(i);
            }
        }
        return ans;
    }
};