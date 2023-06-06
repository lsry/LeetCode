#include <vector>
#include <map>
using std::vector;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        std::map<vector<int>, int> rows, cols;
        for (vector<int> const & g : grid) {
            rows[g] += 1;
        }
        int N = grid.size();
        for (int i = 0;i < N;++i) {
            vector<int> col;
            for (int j = 0;j < N;++j) {
                col.push_back(grid[j][i]);
            }
            cols[col] += 1;
        }
        int ans{0};
        for (auto &[r, n] : rows) {
            ans += n * cols[r];
        }
        return ans;
    }
};