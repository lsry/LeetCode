#include <vector>
using std::vector;
#include <array>
#include <queue>

class Solution {
    constexpr static std::array<std::array<int, 2>, 8> 
        indics{{{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        if (N < 1) {
            return 0;
        }
        if (grid[0][0] == 1) {
            return -1;
        }
        vector<vector<bool>> flags(N, vector<bool>(N, false));
        flags[0][0] = true;
        std::queue<std::pair<int, int>> q;
        q.emplace(std::make_pair(0, 1));
        while (!q.empty()) {
            auto [pos, count] = q.front();
            q.pop();
            int x = pos / N, y = pos % N;
            if (x == N - 1 && y == N - 1) {
                return count;
            }
            for (std::array<int, 2> const &index : indics) {
                int nx = x + index[0], ny = y + index[1];
                if (nx >= 0 && nx < N && ny < N && ny >= 0 && grid[nx][ny] == 0 && !flags[nx][ny]) {
                    flags[nx][ny] = true;
                    q.push(std::make_pair(nx * N + ny, count + 1));
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> arr{{0,0,0},{1,1,0},{1,1,0}};
    s.shortestPathBinaryMatrix(arr);
    return 0;
}
