#include <vector>
using std::vector;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int a = 0, b = 0, c = 0;
        for (vector<int> &cost : costs) {
            int t1 = a, t2 = b, t3 = c;
            a = std::min(t2, t3) + cost[0];
            b = std::min(t1, t3) + cost[1];
            c = std::min(t1, t2) + cost[2];
        }
        return std::min(a, std::min(b, c));
    }
};