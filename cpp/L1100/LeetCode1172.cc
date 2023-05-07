#include <vector>
#include <stack>
#include <queue>

class DinnerPlates {
    int capacity;
    std::vector<std::stack<int>> sts;
    std::priority_queue<int, std::vector<int>, std::greater<int>> lefts;
    std::priority_queue<int, std::vector<int>, std::less<int>> rights;
public:
    DinnerPlates(int capacity): capacity(capacity) {}
    
    void push(int val) {
        while (!lefts.empty() && sts[lefts.top()].size() == capacity) {
            lefts.pop();
        }
        int left = 0;
        if (lefts.empty()) {
            sts.push_back({});
            left = sts.size() - 1;
        } else {
            left = lefts.top();
            lefts.pop();
        }
        sts[left].push(val);
        rights.push(left);
        if (sts[left].size() < capacity) {
            lefts.push(left);
        }
    }
    
    int pop() {
        while (!rights.empty() && sts[rights.top()].empty()) {
            rights.pop();
        }
        if (rights.empty()) {
            return -1;
        } 
        int p{rights.top()};
        int val{sts[p].top()};
        sts[p].pop();
        lefts.push(p);
        return val;
    }
    
    int popAtStack(int index) {
        if (index >= sts.size() || sts[index].empty()) {
            return -1;
        }
        int val{sts[index].top()};
        sts[index].pop();
        lefts.push(index);
        return val;
    }
};