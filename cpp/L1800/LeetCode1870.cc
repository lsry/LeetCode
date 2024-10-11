#include <vector>
using std::vector;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low{1}, high{1'000'000'1};
        while (low < high) {
            int mid = (low + high) / 2;
            double t = 0.0;
            for (int i = 0;i < dist.size();++i) {
                if (i < dist.size() - 1) {
                    t += (dist[i] % mid == 0 ? dist[i] / mid : dist[i] / mid + 1) * 1.0;
                } else {
                    t += 1.0 * dist[i] / mid;
                }
            }
            if (t > hour) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low > 1'000'000'0 ? -1 : high;
    }
};