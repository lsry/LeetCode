#include <vector>
using std::vector;

#include <stack>
#include <queue>

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> sq;
        for (int st : students) {
            sq.push(st);
        }
        std::stack<int> st;
        for (auto b = sandwiches.rbegin();b != sandwiches.rend();++b) {
            st.push(*b);
        }
        while (!st.empty() && !sq.empty()) {
            bool flag{true};
            std::size_t qz{sq.size()};
            for (std::size_t i{0};i < qz;++i) {
                if (st.top() == sq.front()) {
                    st.pop();
                    sq.pop();
                    flag = false;
                    break;
                } else {
                    sq.push(sq.front());
                    sq.pop();
                }
            }
            if (flag) {
                break;
            }
        }
        return (int)sq.size();
    }
};