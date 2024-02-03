#include <stack>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        std::stack<int> st;
        int N = heights.size();
        vector<int> res(N, 0);
        for (int i = N - 1;i >= 0;--i) {
            while (!st.empty()) {
                res[i] += 1;
                if (st.top() > heights[i]) {
                    break;
                }
                st.pop();
            }
            st.push(heights[i]);
        }
        return res;
    }
};