#include <vector>
using std::vector;

#include <queue>

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        std::priority_queue<int> pq;
        int ans = 0;
        std::size_t sz{stations.size()};
        std::size_t idx{0};
        int dis{0}, remain{startFuel};
        while (dis < target) {
            if (remain == 0) {
                if (!pq.empty()) {
                    remain += pq.top();
                    pq.pop();
                    ++ans;
                } else {
                    return -1;
                }
            }
            dis += remain;
            remain = 0;
            while (idx < sz && dis >= stations[idx][0]) {
                pq.push(stations[idx][1]);
                ++idx;
            }
        }
        return ans;
    }
};