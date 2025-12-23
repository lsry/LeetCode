#include <algorithm>
#include <vector>
using std::vector;

struct Node {
    int op, time, value;

    Node(int op, int time, int value): op(op), time(time), value(value) {}
};
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<Node> v;
        for (vector<int> const &event : events) {
            v.emplace_back(0, event[0], event[2]);
            v.emplace_back(1, event[1], event[2]);
        }
        std::sort(v.begin(), v.end(), [](Node const &n1, Node const &n2) {
            return n1.time == n2.time ? n1.op < n2.op : n1.time < n2.time;
        });
        int ans{0};
        int f1{0};
        for (Node const &n : v) {
            if (n.op == 0) {
                ans = std::max(ans, n.value + f1);
            } else {
                f1 = std::max(f1, n.value);
            }
        }
        return ans;
    }
};
