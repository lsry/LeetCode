#include <vector>
using std::vector;
#include <cmath>
#include <functional>
#include <algorithm>

/**
 * S= ​∣x1​(y2​−y3​)+x2​(y3​−y1​)+x3​(y1​−y2​)∣ / 2
 */
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        std::function<double(vector<int> const, vector<int> const, vector<int> const)> calArea 
                = [](vector<int> const &p1, vector<int> const &p2, vector<int> const &p3) -> double {
            int det = p2[0] * p3[1] - p3[0] * p2[1] - p1[0] * p3[1] + p3[0] * p1[1] + p1[0] * p2[1] - p2[0] * p1[1];
            return std::abs(det) / 2.0;
        };
        std::size_t pz{points.size()};
        double area = 0.0;
        for (std::size_t i{0};i < pz - 2;++i) {
            for (std::size_t j{i + 1};j < pz - 1;++j) {
                for (std::size_t k{j + 1};k < pz;++k) {
                    double curArea = calArea(points[i], points[j], points[k]);
                    area = std::max(area, curArea);
                }
            }
        }
        return area;
    }
};