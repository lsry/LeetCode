#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int time{0};
        int taskTime{0};
        int id{0};
        for (vector<int> const &log : logs) {
            if (log[1] - time > taskTime || log[1] - time == taskTime && log[0] < id) {
                taskTime = log[1] - time;
                id = log[0];
            }
            time = log[1];
        }
        return id;
    }
};