#include <functional>
#include <set>
#include <unordered_map>
#include <vector>
using std::vector;

struct TaskInfo {
    int taskId;
    int priorityId;
    int userId;
    bool deleted;

    TaskInfo(int taskId, int priorityId, int userId): taskId(taskId), priorityId(priorityId), userId(userId), deleted(false) {}

    TaskInfo(TaskInfo const &cur) = default;

    TaskInfo() {}
};

class TaskManager {
    std::unordered_map<int, std::set<int, std::greater<int>>> priorityTasks;
    std::set<int, std::greater<int>> priorityIds;
    std::unordered_map<int, TaskInfo> taskInfos;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int> const &task : tasks) {
            taskInfos.emplace(task[1], TaskInfo(task[1], task[2], task[0]));
            priorityTasks[task[2]].emplace(task[1]);
            priorityIds.emplace(task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfos.emplace(taskId, TaskInfo(taskId, priority, userId));
        priorityTasks[priority].emplace(taskId);
        priorityIds.emplace(priority);
    }
    
    void edit(int taskId, int newPriority) {
        TaskInfo &curTask = taskInfos[taskId];
        priorityTasks[curTask.priorityId].erase(taskId);
        if (priorityTasks[curTask.priorityId].empty()) {
            priorityIds.erase(curTask.priorityId);
        }
        priorityTasks[newPriority].emplace(taskId);
        curTask.priorityId = newPriority;
        priorityIds.emplace(newPriority);
    }
    
    void rmv(int taskId) {
        auto iter = taskInfos.find(taskId);
        if (iter != taskInfos.end()) {
            priorityTasks[iter->second.priorityId].erase(taskId);
            if (priorityTasks[iter->second.priorityId].empty()) {
                priorityIds.erase(iter->second.priorityId);
            }
            taskInfos.erase(iter);
        }
    }
    
    int execTop() {
        if (priorityIds.empty()) {
            return -1;
        }
        int taskId = *(priorityTasks[*priorityIds.begin()].begin());
        TaskInfo &curTask = taskInfos[taskId];
        int userId = curTask.userId;
        rmv(taskId);
        return userId;
    }
};

int main() {
    vector<vector<int>> a{{1,101,10},{2,102,20}, {3,103,15}};
    TaskManager manager(a);
    manager.add(4,104,5);
}