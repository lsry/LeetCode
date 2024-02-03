#include <vector>
using std::vector;

class Solution {
    int getGoalDiff(vector<vector<vector<int>>> &goals, int left, int right, vector<int> const &preSum, int who) {
        if (left > right) {
            return 0;
        }
        if (goals[left][right][who] != -1) {
            return goals[left][right][who];
        }
        int diff1 = getGoalDiff(goals, left + 1, right, preSum, 1 - who);
        int sumLeft = preSum[right] - preSum[left];
        int diff2 = getGoalDiff(goals, left, right - 1, preSum, 1 - who);
        int sumRight = preSum[right - 1] - preSum[left - 1];
        if (who == 0) {
            goals[left][right][who] = diff1 + sumLeft > diff2 + sumRight ? diff1 + sumLeft : diff2 + sumRight;
        } else {
            goals[left][right][who] = diff1 - sumLeft < diff2 - sumRight? diff1 - sumLeft : diff2 - sumRight;
        }
        return goals[left][right][who];
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int N = stones.size();
        vector<int> preSum(N + 1, 0);
        for (int i = 1;i <= N;++i) {
            preSum[i] = preSum[i - 1] + stones[i - 1];
        }
        vector<vector<vector<int>>> goals(N + 1, vector<vector<int>>(N + 1, vector<int>(2, -1)));
        int diff = getGoalDiff(goals, 1, N, preSum, 0);
        return diff;
    }
};