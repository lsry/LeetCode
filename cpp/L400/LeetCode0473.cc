#include <vector>
using std::vector;

#include <numeric>
#include <algorithm>
#include <array>

class Solution {
private:
    bool dfs(vector<int> &sticks, std::array<int, 4> &edgeSum, int index, int edge) {
        if (index >= sticks.size()) {
            return true;
        }
        for (int i = 0;i < 4;++i) {
            if (edgeSum[i] + sticks[index] > edge) {
                continue;
            }
            edgeSum[i] += sticks[index];
            if (dfs(sticks, edgeSum, index + 1, edge)) {
                return true;
            }
            edgeSum[i] -= sticks[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum == 0 || sum % 4 != 0) {
            return false;
        }
        std::stable_sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
        int edge = sum / 4;
        std::array<int, 4> edgeSum{{0}};
        return dfs(matchsticks, edgeSum, 0, edge);
    }
};