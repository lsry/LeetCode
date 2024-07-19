#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<int> row(N, 0), col(M, 0);
        for (int i{0};i < M;++i) {
            for (int j{0};j < N;++j) {
                row[j] = std::max(row[j], grid[i][j]);
                col[i] = std::max(col[i], grid[i][j]);
            }
        }
        int ans{0};
        for (int i{0};i < M;++i) {
            for (int j{0};j < N;++j) {
                int x{std::min(col[i], row[j])};
                if (x > grid[i][j]) {
                    ans += x - grid[i][j];
                }
            }
        }
        return ans;
    }
};