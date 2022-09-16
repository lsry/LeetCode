#include <vector>
using std::vector;
#include <algorithm>

class Solution {
private:
    int pz{0};
    int pathTrace(vector<vector<int>>& pairs, int index, vector<int> &length) {
        if (index >= pz) {
            return 0;
        }
        if (length[index] != -1) {
            return length[index];
        }
        int ans = 1;
        for (int i = index + 1;i < pz;++i) {
            if (pairs[i][0] > pairs[index][1]) {
                ans = std::max(ans, 1 + pathTrace(pairs, i, length));
            }
        }
        length[index] = ans;
        return ans;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        pz = pairs.size();
        if (pz < 2) {
            return pz;
        }
        std::stable_sort(pairs.begin(), pairs.end(), [](vector<int> const &v1, vector<int> const &v2) -> bool {
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
        });
        vector<int> length(pz, -1);
        int ans = 0;
        for (int i = 0;i < pz;++i) {
            pathTrace(pairs, i, length);
            ans = std::max(ans, length[i]);
        }
        return ans;
    }
};