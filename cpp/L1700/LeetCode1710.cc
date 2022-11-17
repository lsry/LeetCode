#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(),boxTypes.end(), [](auto const &boxa, auto const &boxb) -> bool {
            return boxa[1] >= boxb[1];
        });
        int units{0}, trucks{0};
        for (vector<int> const &box : boxTypes) {
            if (trucks + box[0] > truckSize) {
                units += (truckSize - trucks) * box[1];
                break;
            }
            units += box[1] * box[0];
            trucks += box[0];
        }
        return units;
    }
};