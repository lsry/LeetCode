#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    int binary(vector<vector<int>> const &events, int endTime) {
        int lo{0}, high = events.size();
        while (lo < high) {
            int mid = (high + lo) / 2;
            if (events[mid][1] >= endTime) {
                high = mid;
            } else {
                lo = mid + 1;
            }
        }
        return high;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        std::sort(events.begin(), events.end(), [](vector<int> const &p1, vector<int> const &p2) {
            return p1[1] < p2[1];
        });
        int N = events.size();
        vector<vector<int>> dp(N + 1, vector<int>(k + 1, 0));
        for (int i = 0;i < N;++i) {
            int ri = binary(events, events[i][0]);
            for (int j = 1;j <= k;++j) {
                dp[i + 1][j] = std::max(dp[i][j], dp[ri][j - 1] + events[i][2]);
            }
        }
        return dp[N][k];
    }
};