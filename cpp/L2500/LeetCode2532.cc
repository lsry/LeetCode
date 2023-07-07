#include <vector>
using std::vector;
#include <queue>
#include <limits>

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        auto f{[&](int x, int y) {
            int t1 = time[x][0] + time[x][2];
            int t2 = time[y][0] + time[y][2];
            return t1 == t2 ? x < y : t1 < t2;        
        }};
        std::priority_queue<int, vector<int>, decltype(f)> leftBridge(f), rightBridge(f);
        // first: time, second: id
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> leftWork, rightWork;
        for (int i = 0;i < time.size();++i) {
            leftBridge.emplace(i);
        }
        int curTime{0};
        while (n > 0 || !rightBridge.empty() || !rightWork.empty()) {
            while (!rightWork.empty() && rightWork.top().first <= curTime) {
                auto [t, id] = rightWork.top();
                rightWork.pop();
                rightBridge.emplace(id);
            }
            while (!leftWork.empty() && leftWork.top().first <= curTime) {
                auto [t, id] = leftWork.top();
                leftWork.pop();
                leftBridge.emplace(id);
            }
            if (!rightBridge.empty()) {
                int id = rightBridge.top();
                rightBridge.pop();
                leftWork.emplace(std::make_pair(curTime + time[id][2] + time[id][3], id));
                curTime = curTime + time[id][2];
            } else if (n > 0 && !leftBridge.empty()) {
                --n;
                int id = leftBridge.top();
                leftBridge.pop();
                rightWork.emplace(std::make_pair(curTime + time[id][0] + time[id][1], id));
                curTime = curTime + time[id][0];
            } else {
                int temp{std::numeric_limits<int>::max()};
                if (!rightWork.empty()) {
                    temp = std::min(temp, rightWork.top().first);
                }
                if (!leftWork.empty()) {
                    temp = std::min(temp, leftWork.top().first);
                }
                if (temp != std::numeric_limits<int>::max()) {
                    curTime = std::max(curTime, temp);
                }
            }
        }
        return curTime;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> w{{1, 1, 2, 1}, {1, 1, 3, 1}, {1, 1, 4, 1}};
    //s.findCrossingTime(3, 3, w);
    vector<vector<int>> w2{{1, 9, 1, 8}, {10, 10, 10, 10}};
    //s.findCrossingTime(3, 2, w2);
    vector<vector<int>> w3{{2,10,5,8}, {3,5,2,2},{5,8,10,10},{7,8,8,5},{5,6,6,10},{6,10,6,2}};
    s.findCrossingTime(10, 6, w3);
    return 0;
}
