#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> rows(2, vector<int>(N, std::numeric_limits<int>::max()));
        for (int i = 0;i < N;++i) {
            rows[0][i] = grid[0][i];
        }
        int id{0};
        for (int i = 1;i < M;++i) {
            for (int j = 0;j < N;++j) {
                rows[1 - id][j] = std::numeric_limits<int>::max();
                for (int k = 0;k < N;++k) {
                    rows[1 - id][j] = std::min(rows[1 - id][j], moveCost[grid[i - 1][k]][j] + grid[i][j] + rows[id][k]);
                }
            }
            id = 1 - id;
        }
        return *std::min_element(rows[id].begin(), rows[id].end());
    }
};

int main() {
    Solution s;
    vector<vector<int>> v1{{5,3}, {4,0}, {2,1}};
    vector<vector<int>> v2{{9,8},{1,5}, {10,12}, {18, 6}, {2,4},{14,3}};
    s.minPathCost(v1, v2);
}