#include <vector>
using std::vector;

#include <numeric>
#include <cmath>

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int distance{std::numeric_limits<int>::max()};
        bool find{false};
        int pz{static_cast<int>(points.size())};
        int index = -1;
        for (int i{0};i < pz;++i) {
            if (points[i][0] == x || points[i][1] == y) {
                int d{std::abs(x - points[i][0]) + std::abs(y - points[i][1])};
                if (d < distance) {
                    distance = d;
                    index = i;
                }
            }
        }
        return index;
    }
};