#include <vector>
using std::vector;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps{0}, curCap{capacity};
        for (int i = 0;i < plants.size();++i) {
            ++steps;
            if (curCap < plants[i]) {
                curCap = capacity;
                steps += (i + 1) * 2  - 2;
            }
            curCap -= plants[i];
        }
        return steps;
    }
};