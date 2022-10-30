#include <vector>
using std::vector;

#include <algorithm>

class Task {
public:
    int _start;
    int _end;
    int _profit;
    Task(int start, int end, int profit): _start(start), _end(end), _profit(profit) {}
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        std::size_t n{startTime.size()};
        std::vector<Task> tasks;
        for (std::size_t i{0};i < n;++i) {
            tasks.push_back(Task(startTime[i], endTime[i], profit[i]));
        }
        std::stable_sort(tasks.begin(), tasks.end(), [&](const Task &t1, const Task &t2) -> bool {
            return t1._end < t2._end;
        });
        vector<int> dp(n + 1, 0);
        for (int i = 1;i <= n;++i) {
            int k = std::upper_bound(tasks.begin(), tasks.begin() + i - 1, tasks[i - 1]._start, 
            [&](int time, Task const &task) -> bool {
                return time < task._end;
            }) - tasks.begin();
            dp[i] = std::max(dp[i - 1], dp[k] + tasks[i - 1]._profit);
        }
        return dp[n];
    }
};