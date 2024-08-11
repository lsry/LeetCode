#include <cstdlib>
#include <limits>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    int ans;
    void dfs(vector<std::pair<int, int>> const &stones, int index, vector<std::pair<int, int>> const &emptys, vector<bool> &flags, int step) {
        if (index == stones.size()) {
            ans = std::min(step, ans);
        }
        for (int i = 0;i < flags.size();++i) {
            if (!flags[i]) {
                flags[i] = true;
                int curStep = std::abs(stones[index].first - emptys[i].first) + std::abs(stones[index].second - emptys[i].second);
                dfs(stones, index + 1, emptys, flags, step + curStep);
                flags[i] = false;
            }
        }
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<std::pair<int, int>> stones, emptys;
        int N = grid.size();
        for (int i = 0;i < N;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 0) {
                    emptys.emplace_back(std::pair<int, int>(i, j));
                } else if (grid[i][j] > 1) {
                    for (int k = 2;k <= grid[i][j];++k) {
                        stones.emplace_back(std::pair<int, int>(i, j));
                    }
                }
            }
        }
        vector<bool> flags(stones.size(), false);
        ans = std::numeric_limits<int>::max();
        dfs(stones, 0, emptys, flags, 0);
        return ans;
    }
};