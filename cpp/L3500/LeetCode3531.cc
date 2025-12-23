#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        std::vector<int> rMin(n + 1, n + 11), rMax(n + 1, 0), cMin(n + 1, n + 1), cMax(n + 1, 0);
        for (vector<int> const &building : buildings) {
            rMin[building[0]] = std::min(rMin[building[0]], building[1]);
            rMax[building[0]] = std::max(rMax[building[0]], building[1]);
            cMin[building[1]] = std::min(cMin[building[1]], building[0]);
            cMax[building[1]] = std::max(cMax[building[1]], building[0]);
        }
        int ans{0};
        for (vector<int> const &building : buildings) {
            if (building[1] > rMin[building[0]] && building[1] < rMax[building[0]] &&
                building[0] > cMin[building[1]] && building[0] < cMax[building[1]]) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v{{1,1}, {1, 2}, {2, 1}, {2,2}};
    s.countCoveredBuildings(3, v);
}
