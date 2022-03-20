#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <unordered_map>
using std::unordered_map;

class Solution {
private:
    std::size_t n;
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        n = patience.size();
        vector<int> distance(n, -1);
        distance[0] = 0;
        unordered_map<int, vector<int>> map;
        for (const vector<int> &edge : edges) {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        queue<int> tq;
        tq.push(0);
        int step = 1;
        while (!tq.empty()) {
            int tz = tq.size();
            for (int i = 0;i < tz;++i) {
                int cur = tq.front();
                tq.pop();
                vector<int> &next = map[cur];
                for (int &ni : next) {
                    if (distance[ni] == -1 && ni != 0) {
                        distance[ni] = step;
                        tq.push(ni);
                    }
                }
            }
            ++step;
        }
        int freeTime = 0;
        for (std::size_t i = 1;i < n;++i) {
            int rt = distance[i] * 2;
            int lt = rt;
            if (patience[i] > 0 && patience[i] < rt) {
                int times = (rt - 1) / patience[i];
                lt = times * patience[i] + rt;
            }
            freeTime = std::max(freeTime, lt + 1);
        }
        return freeTime;
    }
};