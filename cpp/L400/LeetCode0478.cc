#include <vector>
using std::vector;

#include <cmath>
#include <random>

class Solution {
private:
    double radius;
    double centerX, centerY;
    std::random_device rd; 
    std::mt19937 gen{rd()};
public:
    Solution(double radius, double x_center, double y_center)
        : radius(radius), centerX(x_center), centerY(y_center) {}
    
    vector<double> randPoint() {
        std::uniform_real_distribution<double> angle_dis(0, 2 * M_PI);
        std::uniform_real_distribution<double> r_dis(0, radius * radius);
        double angle = angle_dis(gen);
        double r = std::sqrt(r_dis(gen));
        return {centerX + r * std::cos(angle), centerY + std::sin(angle)};
    }
};