#include <vector>
using std::vector;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> counts(n, vector<int>(11, 0));
        for (vector<int> const &p : pick) {
            counts[p[0]][p[1]] += 1;
        }
        int ans{0};
        for (int i = 0;i < n;++i) {
            for (int x : counts[i]) {
                if (x > i) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};