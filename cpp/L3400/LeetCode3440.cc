#include <functional>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        std::priority_queue<int, vector<int>, std::less<int>> pq;
        int lastTime{0};
        int N = startTime.size();
        for (int i = 0;i < N;++i) {
            pq.push(startTime[i] - lastTime);
            lastTime = endTime[i];
            if (i == N - 1) {
                pq.push(eventTime - endTime[i]);
            }
        }      
        int ans{0};
        lastTime = 0;
        for (int i = 0;i < N;++i) {
            int t1 = startTime[i] - lastTime;
            int t2 = i == N - 1 ? eventTime - endTime[i] : startTime[i + 1] - endTime[i];
            if (t1 < t2) {
                std::swap(t1, t2);
            }
            bool f1{false}, f2{false};
            if (!pq.empty() && pq.top() == t1) {
                f1 = true;
                pq.pop();
            }
            if (!pq.empty() && pq.top() == t2) {
                f2 = true;
                pq.pop();
            }
            int time = t1 + t2 + (!pq.empty() && pq.top() >= endTime[i] - startTime[i] ? endTime[i] - startTime[i] : 0);
            ans = std::max(time, ans);
            if (f1) {
                pq.push(t1);
            }
            if (f2) {
                pq.push(t2);
            }
            lastTime = endTime[i];
        }
        return ans;
    }
};