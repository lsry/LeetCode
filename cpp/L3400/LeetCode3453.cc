#include <cstdlib>
#include <limits>
#include <vector>
using std::vector;

class Solution {
    double computeArea(vector<vector<int>> const &squares, double Y) {
        double area{0};
        for (vector<int> const &square : squares) {
            if (square[1] + square[2] <= Y) {
                area += 1.0 * square[2] * square[2];
            } else if (square[1] >= Y) {
                break;
            } else {
                area += (Y - square[1]) * square[2];
            }
        }
        return area;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double minY{std::numeric_limits<double>::max()}, maxY{0.0}, area{0.0};
        for (vector<int> const & square : squares) {
            minY = std::min(minY, 1.0 *square[1]);
            maxY = std::max(maxY, 1.0 * (square[1] + square[2]));
            area += 1.0 * square[2] * square[2];
        }
        double halfArea = area / 2.0;
        double y = std::numeric_limits<double>::max();
        double ya = std::numeric_limits<double>::max();
        while ((minY - maxY) < 1e-5) {
            double halfY = (minY + maxY) / 2.0;
            double curArea = computeArea(squares, halfY);
            double curAreaDis = std::abs(curArea - halfArea);
            if (curAreaDis < ya || (std::abs(curAreaDis - ya) <= 1e-5 && y > halfY)) {
                y = halfY;
                ya = std::abs(curArea - halfArea);
            }
            if (curArea < halfArea) {
                minY = halfY + 1e-5;
            } else {
                maxY = halfY - 1e-5;
            }
        }
        return y;
    }
};
