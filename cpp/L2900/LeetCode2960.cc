#include <vector>
using std::vector;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans{0};
        int step{0};
        for (int percent : batteryPercentages) {
            int cur{std::max(0, percent - step)};
            if (cur == 0) {
                continue;
            } else {
                ++ans;
                ++step;
            }
        }
        return ans;
    }
};