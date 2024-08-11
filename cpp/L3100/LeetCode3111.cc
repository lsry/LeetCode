#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        std::sort(points.begin(), points.end(), [](vector<int> const &p1, vector<int> const &p2) {
            return p1[0] < p2[0];
        });
        int ans{0};
        int N = points.size();
        for (int i = 0;i < N;) {
            ++ans;
            int j = i;
            while (j < N && points[j][0] - points[i][0] <= w) {
                ++j;
            }
            i = j;
        }
        return ans;
    }
};