#include <utility>
#include <vector>
using std::vector;

class Solution {
    std::pair<int, int> trace(vector<int> &cost, int id) {
        if (id >= cost.size()) {
            return {0, -1};
        }
        auto [lm, la] = trace(cost, id * 2 + 1);
        auto [rm, ra] = trace(cost, id * 2 + 2);
        if (la == -1 || ra == -1) {
            return {cost[id], 0};
        }
        int maxM = std::max(lm, rm);
        int minM = std::min(lm, rm);
        return {maxM + cost[id], la + ra + maxM - minM};
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        auto [m, a] = trace(cost, 0);
        return a;
    }
};