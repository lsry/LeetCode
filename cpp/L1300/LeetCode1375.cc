#include <vector>
using std::vector;
#include <unordered_set>

class Solution {
public:
    // Time: 7.14%, 136ms
    int numTimesAllBlueLong(vector<int>& flips) {
        int ans{0};
        int N = flips.size();
        std::unordered_set<int> visited, waited;
        for (int i = 0;i < N;++i) {
            if (visited.find(i + 1) == visited.end()) {
                waited.emplace(i + 1);
            }
            if (waited.find(flips[i]) != waited.end()) {
                waited.erase(flips[i]);
            } else {
                visited.emplace(flips[i]);
            }
            if (waited.empty()) {
                ++ans;
            }
        }
        return ans;
    }

    // Time: 48ms, 72%
    int numTimesAllBlue(vector<int>& flips) {
        int ans{0};
        int N = flips.size();
        vector<bool> visited(N, false);
        int waited{0};
        for (int i = 0;i < N;++i) {
            if (!visited[i]) {
                ++waited;
            }
             visited[flips[i] - 1] = true;
            if (flips[i] - 1 <= i) {
               --waited;
            }
            if (waited == 0) {
                ++ans;
            }
        }
        return ans;
    }
};