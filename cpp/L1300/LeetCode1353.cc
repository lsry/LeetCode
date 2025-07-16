#include <algorithm>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int maxDay{0};
        for (vector<int> const &event : events) {
            maxDay = std::max(maxDay, event[1]);
        }
        std::sort(events.begin(), events.end(), [](vector<int> const &e1, vector<int> const &e2) {
            return e1[0] < e2[0];
        });
        auto f{[](vector<int> const &e1, vector<int> const &e2) {
            return e1[1] > e2[1];
        }};
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(f)> pq;
        int ans{0};
        for (int day{1}, j = 0;day <= maxDay;++day) {
            while (j < events.size() && events[j][0] <= day) {
                if (events[j][1] < day) {
                    continue;
                }
                pq.push(events[j]);
                ++j;
            }
            while (!pq.empty() && pq.top()[1] < day) {
                pq.pop();
            }
            if (!pq.empty()) {
                ++ans;
                pq.pop();
            }
        }
        return ans;
    }
};