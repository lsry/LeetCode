#include <vector>
using std::vector;
#include <cmath>

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int minX{100}, maxX{0};
        int minY{100}, maxY{0};
        for (vector<int> &tower : towers) {
            minX = std::min(minX, tower[0]);
            maxX = std::max(maxX, tower[0]);
            minY = std::min(minY, tower[1]);
            maxY = std::max(maxY, tower[1]);
        }
        vector<int> res{0,0};
        int q{0};
        for (int y{minY};y <= maxY;++y) {
            for (int x{minX};x <= maxX;++x) {
                int qt{0};
                for (vector<int> const &tower : towers) {
                    int dx = tower[0] - x;
                    int dy = tower[1] - y;
                    double dis = std::sqrt(dx * dx + dy * dy);
                    if (dis <= radius * 1.0) {
                        qt += int(tower[2] / (dis + 1.0));
                    }
                }
                if (qt > q || (qt == q && (x < res[0] || y < res[1]))) {
                    q = qt;
                    res[0] = x;
                    res[1] = y;
                }
            }
        }
        return res;
    }
};