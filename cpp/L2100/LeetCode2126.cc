#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        std::sort(asteroids.begin(), asteroids.end());
        unsigned long long int q = mass;
        for (int asteroid : asteroids) {
            if (q < asteroid) {
                return false;
            }
            q += asteroid;
        }
        return true;
    }
};
