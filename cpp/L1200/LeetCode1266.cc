#include <algorithm>
#include <cstdlib>
#include <vector>
using std::vector;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans{0};
        int pz = points.size();
        for (int i = 1;i < pz;++i) {
            int minX = std::min(std::abs(points[i][0] - points[i - 1][0]), std::abs(points[i][1] - points[i - 1][1]));
            int maxX = std::max(std::abs(points[i][0] - points[i - 1][0]), std::abs(points[i][1] - points[i - 1][1]));
            ans += minX + (maxX - minX);
        }
        return ans;
    }
};
