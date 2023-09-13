#include <vector>
using std::vector;

class Solution {
    bool search(int course, vector<vector<int>> const &prevs, vector<int> &flags, vector<int> &res) {
        if (flags[course] == 2) {
            return true;
        }
        flags[course] = 1;
        for (int prev : prevs[course]) {
            if (flags[prev] == 1) {
                return false;
            }
            if (!search(prev, prevs, flags, res)) {
                return false;
            }
        }
        flags[course] = 2;
        res.push_back(course);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prevs(numCourses, vector<int>());
        for (vector<int> const &p : prerequisites) {
            prevs[p[0]].push_back(p[1]);
        }
        vector<int> flags(numCourses, 0);
        vector<int> res;
        for (int i = 0;i < numCourses;++i) {
            if (!search(i, prevs, flags, res)) {
                return {};
            }
        }
        return res;
    }
};