#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::stable_sort(points.begin(), points.end(), [](auto const &p1, auto const &p2) {
            return p1[0] <= p2[0];
        });
        int ans{0};
        for (std::size_t i{1};i < points.size();++i) {
            ans = std::max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};