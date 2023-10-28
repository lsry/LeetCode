#include <algorithm>
#include <functional>
#include <vector>
using std::vector;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end(), std::greater<int>());
        if (satisfaction.empty() || satisfaction[0] <= 0) {
            return 0;
        }
        int ans{0}, preSum{0};
        for (int sat : satisfaction) {
            int cur{ans + preSum + sat};
            if (cur < ans) {
                break;
            }
            ans = cur;
            preSum += sat;
        }
        return ans;
    }
};