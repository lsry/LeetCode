#include <vector>
using std::vector;
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nexts(numCourses, vector<int>());
        vector<int> prevs(numCourses, 0);
        for (vector<int> const &p : prerequisites) {
            prevs[p[0]] += 1;
            nexts[p[1]].push_back(p[0]);
        }
        std::queue<int> q;
        for (int i = 0;i < numCourses;++i) {
            if (prevs[i] == 0) {
                q.push(i);
            }
        }
        int learnCount{0};
        while (!q.empty()) {
            int c{q.front()};
            q.pop();
            ++learnCount;
            for (int next : nexts[c]) {
                prevs[next] -= 1;
                if (prevs[next] == 0) {
                    q.push(next);
                }
            }
        }
        return learnCount == numCourses;
    }
};