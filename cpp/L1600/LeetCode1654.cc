#include <algorithm>
#include <array>
#include <limits>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
       int f = *std::max_element(forbidden.begin(), forbidden.end());
       int len = std::max(f + a + b, x + b) + b;
       vector<vector<bool>> flags(len, vector<bool>(2, false));
       for (int p : forbidden) {
           flags[p][0] = true;
           flags[p][1] = true;
       }
       std::queue<std::array<int, 3>> q;
       q.push({0, 0, 0});
       while (!q.empty()) {
           std::array<int, 3> pa{q.front()};
           q.pop();
           if (pa[0] == x) {
               return pa[1];
           }
           if (!flags[pa[0]][0] && pa[0] + a < len) {
               q.push({pa[0] + a, pa[1] + 1, 0});
               flags[pa[0]][0] = true;
           }
           if (!flags[pa[0]][1] && pa[2] == 0 && pa[0] - b >= 0) {
               q.push({pa[0] - b, pa[1] + 1, 1});
               flags[pa[0]][1] = true;
           }
       }
       return -1;
    }
};

int main() {
    vector<int> f{1,6,2,14,5,17,4};
    Solution s;
    int r = s.minimumJumps(f, 16, 9, 7);
    return 0;
}