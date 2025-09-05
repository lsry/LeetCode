#include <algorithm>
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
            for (int j = i + 1;j < N;++j) {
                if (points[j][1] > points[i][1]) {
                    continue;
                }
                int minX = std::min(points[i][0], points[j][0]);
                int maxX = std::max(points[i][0], points[j][0]);
                int minY = std::min(points[i][1], points[j][1]);
                int maxY = std::max(points[i][1], points[j][1]);
                bool f{true};
                for (int k = i + 1;k < j;++k) {
                    if (points[k][0] >= minX && points[k][0] <= maxX && points[k][1] >= minY && points[k][1] <= maxY) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};