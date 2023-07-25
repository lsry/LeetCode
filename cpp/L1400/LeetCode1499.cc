#include <vector>
using std::vector;
#include <queue>
#include <limits>

class Solution {
    /**
     * yi + yj + |xi - xj|
     * = yi - xi + xj + yj  when i < j, xi < xj
     */
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        auto cmp{[](vector<int> const &p1, vector<int> const &p2) {
            return p1[1] - p1[0] < p2[1] - p2[0];
        }};
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        int ans{std::numeric_limits<int>::min()};
        for (vector<int> const &p : points) {
            while (!pq.empty() && p[0] - pq.top()[0] > k) {
                pq.pop();
            }
            if (!pq.empty()) {
                vector<int> tp{pq.top()};
                ans = std::max(ans, p[0] + p[1] + tp[1] - tp[0]);
            }
            pq.push(p);
        }
        return ans;
    }
};