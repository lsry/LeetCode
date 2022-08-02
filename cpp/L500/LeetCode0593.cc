#include <vector>
using std::vector;

#include <cmath>

class Solution {
    constexpr static double EPLISION = 1e-6;

    bool doubleEqule(double d1, double d2) {
        return std::abs(d1 - d2) <= EPLISION;
    }

    double distance(vector<int>& p1, vector<int>& p2) {
        int d1 = p2[0] - p1[0], d2 = p2[1] - p1[1];
        return std::sqrt(d1 * d1 + d2 * d2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return diagram(p1, p2, p3, p4) || diagram(p1, p3, p2, p4) || diagram(p2, p3, p1, p4);
    }

    bool diagram(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        double m1x = (p1[0] + p2[0]) / 2.0, m1y = (p1[1] + p2[1]) / 2.0;
        double m2x = (p3[0] + p4[0]) / 2.0, m2y = (p3[1] + p4[1]) / 2.0;
        if ((!doubleEqule(m1x, m2x)) || (!doubleEqule(m1y, m2y))) {
            return false;
        }
        double d1 = distance(p1, p2), d2 = distance(p3, p4);
        if (!doubleEqule(d1, d2) || doubleEqule(d1, 0.0) || doubleEqule(d2, 0.0)) {
            return false;
        }
        if (doubleEqule(p2[0] - p1[0], 0.0)) {
            return doubleEqule(p3[1] - p4[1], 0.0);
        } else if (doubleEqule(p3[0] - p4[0], 0.0)) {
            return doubleEqule(p2[1] - p1[1], 0.0);
        } else {
            double k1 = (p2[1] - p1[1]) * 1.0 / (p2[0] - p1[0]);
            double k2 = (p3[1] - p4[1]) * 1.0 / (p3[0] - p4[0]);
            return doubleEqule(k1 * k2, -1.0);
        }
    }
};
