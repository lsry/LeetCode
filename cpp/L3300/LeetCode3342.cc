#include <vector>
using std::vector;
#include <array>
#include <queue>

class Solution {
    constexpr static std::array<std::array<int, 2>, 4> indics{{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int M = moveTime.size(), N = moveTime[0].size();
        vector<bool> visited(M * N, false);
        auto cmp{[](std::tuple<int, int, int> const &p1, std::tuple<int, int, int> const &p2) {
            return std::get<1>(p1) > std::get<1>(p2);
        }};
        std::priority_queue<std::tuple<int, int, int>, vector<std::tuple<int, int, int>>, decltype(cmp)> pq(cmp);
        pq.push(std::tuple<int, int, int>(0, 0, 1));
        while (!pq.empty()) {
            auto [p, d, s] = pq.top();
            pq.pop();
            if (visited[p]) {
                continue;
            }
            visited[p] = true;
            int x = p / N, y = p % N;
            if (x == M - 1 && y == N - 1) {
                return d;
            }
            for (std::array<int, 2> const &index : indics) {
                int nx = index[0] + x;
                int ny = index[1] + y;
                int next = nx * N + ny;
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[next]) {
                    int nd = std::max(d, moveTime[nx][ny]) + (2 - s);
                    pq.push(std::tuple<int, int, int>(next, nd, 1 - s));
                }
            }
        }
        return -1;
    }
};