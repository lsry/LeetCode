#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](vector<int> const &p1, vector<int> const &p2) {
            return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
        });
        int N = points.size();
        int ans{0};
        for (int i = 0;i < N;++i) {
            int maxY = std::numeric_limits<int>::min();
            for (int j = i + 1;j < N;++j) {
                if (points[j][1] > points[i][1] || points[j][1] <= maxY) {
                    continue;
                }
                ++ans;
                maxY = std::max(maxY, points[j][1]);
            }
        }
        return ans;
    }
};