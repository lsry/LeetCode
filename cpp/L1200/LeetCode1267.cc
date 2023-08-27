#include <vector>
using std::vector;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<int> row(M, 0), col(N, 0);
        for (int i = 0;i < M;++i) {
            for (int j{0};j < N;++j) {
                if (grid[i][j] == 1) {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        int ans{0};
        for (int i = 0;i < M;++i) {
            for (int j{0};j < N;++j) {
                if (grid[i][j] == 1 &&(col[j] >= 2 || row[i] >= 2)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};