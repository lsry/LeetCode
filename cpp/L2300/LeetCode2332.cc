#include <algorithm>
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        std::sort(buses.begin(), buses.end());
        std::sort(passengers.begin(), passengers.end());
        std::unordered_set<int> times(passengers.begin(), passengers.end());
        int ans{-1};
        int p{0};
        int pN = passengers.size();
        int lastTime = -1;
        for (int busTime : buses) {
            if (p >= pN) {
                ans = std::max(ans, busTime);
                continue;
            }
            int p1 = p;
            while (p1 < pN && passengers[p1] <= busTime && p1 - p + 1 <= capacity) {
                int t = passengers[p1] - 1;
                if (t > lastTime) {
                    while (times.contains(t)) {
                        --t;
                    }
                    ans = std::max(ans, t);
                }
                lastTime = passengers[p1];
                ++p1;
            }
            if (p1 - p < capacity) {
                int t = busTime;
                while (times.contains(t)) {
                    --t;
                }
                ans = std::max(ans, t);
            }
            p = p1;
        }    
        return ans;  
    }
};