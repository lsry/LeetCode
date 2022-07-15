#include <vector>
using std::vector;

#include <unordered_map>
#include <cmath>

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd{0}, even{0};
        for (int p : position) {
            if (p % 2 == 0) {
                ++even;
            } else {
                ++odd;
            }
        }
        return even > odd ? odd : even;
    }
};