#include <algorithm>
#include <vector>
using std::vector;
#include <queue>

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        std::sort(courses.begin(), courses.end(), [](vector<int> const &c1, vector<int> const &c2) {
            return c1[1] < c2[1];
        });
        auto f{[&](int x, int y) {
            return courses[x][0] < courses[y][0];
        }};
        std::priority_queue<int, vector<int>, decltype(f)> pq(f);
        int day{0}, ans{0};
        for (int i = 0;i < courses.size();++i) {
            if (day + courses[i][0] <= courses[i][1]) {
                ++ans;
                day += courses[i][0];
                pq.push(i);
            } else if (!pq.empty() && courses[pq.top()][0] > courses[i][0] && day - courses[pq.top()][0] + courses[i][0] <= courses[i][1]) {
                day = day - courses[pq.top()][0] + courses[i][0];
                pq.pop();
                pq.push(i);
            }
        }
        return ans;
    }
};