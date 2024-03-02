#include <queue>
class MyStack {
    std::queue<int> q1, q2;
    int top_num = -1;
    std::queue<int> &qt1, &qt2;
    int sz;
public:
    MyStack(): qt1(q1), qt2(q2), sz(0) {}
    
    void push(int x) {
        qt1.push(x);
        top_num = x;
        ++sz;
    }
    
    int pop() {
        while (qt1.size() > 1) {
            top_num = qt1.front();
            qt2.push(qt1.front());
            qt1.pop();
        }
        int x = qt1.front();
        qt1.pop();
        std::queue<int> &q = qt1;
        qt1 = qt2;
        qt2 = q;
        --sz;
        return x;
    }
    
    int top() {
        return top_num;
    }
    
    bool empty() {
        return sz == 0;
    }
};