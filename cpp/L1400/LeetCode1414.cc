#include <stack>
using std::stack;

int findMinFibonacciNumbers(int k) {
    stack<int> st;
    int a = 1, b = 1;
    while (b <= k) {
        st.push(b);
        int t = b;
        b = a + b;
        a = t;
    }
    int count = 0;
    while (!st.empty()) {
        if (st.top() <= k) {
            count += 1;
            k -= st.top();
        } 
        st.pop(); // 每个菲契那波数字最多使用一次
    }
    return count;
}