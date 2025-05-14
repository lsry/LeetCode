#include <array>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    constexpr static std::array<std::array<int, 2>, 4> indics{{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int M = moveTime.size(), N = moveTime[0].size();
        vector<bool> visited(M * N, false);
        auto cmp{[](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
            return p1.second > p2.second;
        }};
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push(std::pair<int, int>(0, 0));
        while (!pq.empty()) {
            auto [p, d] = pq.top();
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
                    int nd = std::max(d + 1, moveTime[nx][ny] + 1);
                    pq.push(std::pair<int, int>(next, nd));
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> v{{0,4},{4,4}};
    Solution s;
    s.minTimeToReach(v);
}