#include <algorithm>
#include <functional>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        std::sort(cost.begin(), cost.end(), std::greater<int>());
        int N = cost.size();
        int buy{0};
        for (int i = 0;i < N;) {
            buy += cost[i];
            if (i + 1 < N) {
                buy += cost[i + 1];
            }
            i = i + 3;
        }
        return buy;
     }
};
