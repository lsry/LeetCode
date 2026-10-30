#include <array>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    constexpr static std::array<std::array<int, 2>, 4> dirs = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
    int M, N;

    bool check(vector<vector<int>> const &grid, int x, int y, vector<vector<bool>> &visited, int k) {
        int mod{0};
        std::queue<std::pair<int, int>> q;
        q.push(std::pair<int, int>(x, y));
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            visited[a][b] = true;
            mod = (mod + grid[a][b]) % k;
            for (std::array<int, 2> const &dir : dirs) {
                int na = a + dir[0];
                int nb = b + dir[1];
                if (na >= 0 && na < M && nb >= 0 && nb < N && grid[na][nb] > 0 && !visited[na][nb]) {
                    visited[na][nb] = true;
                    q.push(std::pair<int, int>(na, nb));
                }
            }
        }
        return mod == 0;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        M = grid.size();
        N = grid[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        int ans{0};
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] > 0 && !visited[i][j]
                    && check(grid, i, j, visited, k)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
        {0,2,1,0,0},{0,5,0,0,5},{0,0,1,0,0},{0,1,4,7,0},{0,2,0,0,8}
    };
    s.countIslands(grid, 5);
}
