#include <vector>
using std::vector;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low{1}, high{1'000'000'000'000'000};
        while (low < high) {
            long long int mid = low + (high - low) / 2;
            long long int trips{0};
            for (int cur : time) {
                trips += mid / cur;
                if (trips >= totalTrips) {
                    break;
                }
            }
            if (trips >= totalTrips) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};