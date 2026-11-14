#include <functional>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // freeQueue: [weight, serverId], busyQueue: [time, serverId]
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<>> freeQueue;
        std::priority_queue<std::pair<unsigned long long int, int>, vector<std::pair<unsigned long long int, int>>,
                            std::greater<>> busyQueue;
        for (int i = 0;i < servers.size();++i) {
            freeQueue.emplace(std::pair<int, int>(servers[i], i));
        }
        int taskLength = tasks.size();
        vector<int> ans(taskLength, 0);
        unsigned long long int time{0ULL};
        for (int taskId{0};taskId < taskLength;++time) {
            if (freeQueue.empty()) {
                time = busyQueue.top().first;
            }
            while (!busyQueue.empty() && busyQueue.top().first <= time) {
                auto [t, id] = busyQueue.top();
                busyQueue.pop();
                freeQueue.emplace(std::pair<int, int>(servers[id], id));
            }
            while (!freeQueue.empty() && taskId < taskLength && taskId <= time) {
                auto [w, id] = freeQueue.top();
                freeQueue.pop();
                ans[taskId] = id;
                busyQueue.emplace(std::pair<int, int>(time + tasks[taskId], id));
                ++taskId;
            }
        }
        return ans;
    }
};
