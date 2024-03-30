#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    constexpr static long long int MOD{1'000'000'007};
public:
    int countWays(vector<vector<int>>& ranges) {
        if (ranges.empty()) {
            return 0;
        }
        std::sort(ranges.begin(), ranges.end(), [](vector<int> const &r1, vector<int> const &r2) {
            return r1[0] == r2[0] ? r1[1] < r2[1] : r1[0] < r2[0];
        });
        int ans{1};
        int rmax{ranges[0][1]};
        for (int i = 1;i < ranges.size();++i) {
            if (ranges[i][0] <= rmax) {
                rmax = std::max(rmax, ranges[i][1]);
                continue;
            } else {
                ++ans;
                rmax = ranges[i][1];
            }
        }
        long long int count{1};
        for (int i = 0;i < ans;++i) {
            count = (count * 2) % MOD;
        }
        return count;
    }
};