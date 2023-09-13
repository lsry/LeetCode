#include <vector>
using std::vector;
#include <queue>

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> nexts(numCourses, vector<int>());
        vector<int> prevs(numCourses, 0);
        for (vector<int> const &p : prerequisites) {
            nexts[p[0]].push_back(p[1]);
            prevs[p[1]] += 1;
        }
        std::queue<int> q;
        for (int i = 0;i < numCourses;++i) {
            if (prevs[i] == 0) {
                q.push(i);
            }
        }
        vector<vector<bool>> befores(numCourses, vector<bool>(numCourses, false));
        while (!q.empty()) {
            int course{q.front()};
            q.pop();
            for (int next : nexts[course]) {
                prevs[next] -= 1;
                if (prevs[next] == 0) {
                    q.push(next);
                }
                for (int i = 0;i < numCourses;++i) {
                    if (befores[course][i]) {
                        befores[next][i] = true;
                    }
                }
                befores[next][course] = true;
            }
        }
        vector<bool> res;
        for (vector<int> const &query : queries) {
            res.push_back(befores[query[1]][query[0]]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> p{{2,3},{2,1},{0,3},{0,1}};
    vector<vector<int>> q{{0,1}, {0,3}};
    s.checkIfPrerequisite(5, p, q);
}