#include <vector>
using std::vector;

#include <stack>
#include <cmath>
#include <algorithm>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> st;
        for (int x : asteroids) {
            bool wait{true};
            if (x > 0) {
                st.push(x);
            } else {
                int wt = -x;
                while (!st.empty() && st.top() > 0) {
                    int vt = st.top();
                    if (vt < wt) {
                        st.pop();
                    } else if (wt == vt) {
                        st.pop();
                        wait = false;
                        break;
                    } else {
                        wait = false;
                        break;
                    }
                }
                if (wait) {
                    st.push(x);
                }
            }
        }
        vector<int> vi;
        while (!st.empty()) {
            vi.push_back(st.top());
            st.pop();
        }
        std::reverse(vi.begin(), vi.end());
        return vi;
    }
};