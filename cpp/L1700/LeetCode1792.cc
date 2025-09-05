#include <vector>
using std::vector;

#include <queue>

class Solution {
public:
    // 優先安排通過率增加量最大的班級
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto fn{[&](int x, int y) {
            double d1 = (classes[x][0] + 1) * 1.0 / (classes[x][1] + 1) - classes[x][0] * 1.0 / classes[x][1];
            double d2 = (classes[y][0] + 1) * 1.0 / (classes[y][1] + 1) - classes[y][0] * 1.0 / classes[y][1];
            return d1 <= d2;
        }};
        std::priority_queue<int, vector<int>, decltype(fn)> pq(fn);
        int cz = classes.size();
        for (int i = 0;i < cz;++i) {
            pq.push(i);
        }
        for (int i = 0;i < extraStudents;++i) {
            int cur = pq.top();
            pq.pop();
            if (classes[cur][0] == classes[cur][1]) {
                break;
            }
            classes[cur][0] += 1;
            classes[cur][1] += 1;
            pq.push(cur);
        }
        double res = 0.0;
        for (vector<int> &c : classes) {
            res += c[0] * 1.0 / c[1];
        }
        return res / cz;
    }
};