#include <vector>
using std::vector;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) {
            return distanceBetweenBusStops(distance, destination, start);
        }
        int sum = 0, dis = 0;
        for (int i = 0;i < distance.size();++i) {
            sum += distance[i];
            if (i >= start && i < destination) {
                dis += distance[i];
            }
        }
        return std::min(dis, sum - dis);
    }
};