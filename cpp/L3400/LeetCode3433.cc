#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <string_view>
#include <utility>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
     static int stringToInt(std::string_view sv) {
        int num{0};
        for (char c : sv) {
            num = num * 10 + (c - '0');
        }
        return num;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<bool> onlineStatus(numberOfUsers, true);
        vector<int> onlineCount(numberOfUsers, 0);
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        std::sort(events.begin(), events.end(), [](vector<string> const &e1, vector<string> const &e2) {
            int t1 = stringToInt(e1[1]);
            int t2 = stringToInt(e2[1]);
            if (t1 == t2) {
                if (e1[0] == "OFFLINE") {
                    t1 = -1;
                }
                if (e2[0] == "OFFLINE") {
                    t2 = -1;
                }
            }
            return t1 < t2;
        });
        for (vector<string> const &event : events) {
            int timestamp = stringToInt(event[1]);
            while (!pq.empty() && pq.top().first <= timestamp) {
                auto [t, id] = pq.top();
                pq.pop();
                onlineStatus[id] = true;
            }
            if (event[0] == "OFFLINE") {
                int offlineId = stringToInt(event[2]);
                pq.push(std::pair<int, int>(timestamp + 60, offlineId));
                onlineStatus[offlineId] = false;
                continue;
            }
            if (event[2] == "ALL") {
                for (int i = 0;i < numberOfUsers;++i) {
                    onlineCount[i] += 1;
                }
            } else if (event[2] == "HERE") {
                for (int i = 0;i < numberOfUsers;++i) {
                    if (onlineStatus[i]) {
                        onlineCount[i] += 1;
                    }
                }
            } else {
                int sz = event[2].size();
                for (int i = 0;i < sz;) {
                    int id{0};
                    int j{i + 2};
                    while (j < sz && event[2][j] != ' ') {
                        id = id * 10 + (event[2][j] - '0');
                        ++j;
                    }
                    onlineCount[id] += 1;
                    i = j + 1;
                }
            }
        }
        return onlineCount;
    }
};
