#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> ids(plantTime.size(), 0);
        std::iota(ids.begin(), ids.end(), 0);
        std::sort(ids.begin(), ids.end(), [&](int x, int y) {
            return growTime[x] > growTime[y];
        });
        int completeDay{0}, plantDay{0};
        for (int id : ids) {
            completeDay = std::max(completeDay, plantDay + plantTime[id] + growTime[id]);
            plantDay = plantDay + plantTime[id];
        }
        return completeDay;
    }
};