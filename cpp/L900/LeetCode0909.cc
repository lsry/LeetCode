#include <queue>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        std::unordered_map<int, int> mp;
        for (int x = N - 1, y = 0, num{1}, dy{1};num <= N * N;++num) {
            mp[num] = board[x][y];
            y += dy;
            if (y == N || y == -1) {
                y -= dy;
                x -= 1;
                dy = -dy;
            }
        }
        std::queue<int> q;
        q.push(1);
        int step{0};
        vector<bool> visited(N * N + 1, false);
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0;s < sz;++s) {
                int cur{q.front()};
                q.pop();
                visited[cur] = true;
                if (cur == N * N) {
                    return step;
                }
                for (int i = 1;i <= 6;++i) {
                    int next = std::min(cur + i, N * N);
                    if (mp[next] != -1) {
                        next = mp[next];
                    }
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> v{{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    Solution s;
    s.snakesAndLadders(v);
}