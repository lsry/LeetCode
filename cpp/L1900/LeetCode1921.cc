#include <vector>
using std::vector;

#include <queue>
#include <numeric>

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> links(n, vector<int>());
        for (vector<int> &edge : edges) {
            links[edge[0]].push_back(edge[1]);
            links[edge[1]].push_back(edge[0]);
        }
        std::queue<int> q;
        q.push(source);
        vector<bool> flags(n, false);
        flags[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination) {
                return true;
            }
            for (int next : links[node]) {
                if (!flags[next]) {
                    flags[next] = true;
                    q.push(next);
                }
            }
        }
        return false;
    }


    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        auto f{[&](int a, int b) {
            int t1 = dist[a] % speed[a] == 0 ? dist[a] / speed[a] : dist[a] / speed[a] + 1;
            int t2 = dist[b] % speed[b] == 0 ? dist[b] / speed[b] : dist[b] / speed[b] + 1;
            return t1 > t2;
        }};
        std::priority_queue<int, vector<int>, decltype(f)> pq(f);
        for (int i = 0;i < dist.size();++i) {
            pq.emplace(i);
        }
        int ans{0}, time{0};
        while (!pq.empty()) {
            int id{pq.top()};
            pq.pop();
            if (time == 0) {
                ++ans;
                ++time;
                continue;
            }
            int at = dist[id] % speed[id] == 0 ? dist[id] / speed[id] : dist[id] / speed[id] + 1;
            if (at <= time) {
                break;
            }
            ++ans;
            ++time;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v1{3,3,5,7,7}, v2{1,1,4,2,2};
    s.eliminateMaximum(v1, v2);
}