#include <algorithm>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2,  vector<int>());
        std::unordered_map<int, int> mp;
        for  (vector<int> const &match : matches) {
            if (mp.find(match[0]) == mp.end()) {
                mp[match[0]] = 0;
            }
            auto it{mp.find(match[1])};
            if (it == mp.end()) {
                mp[match[1]] = 1;
            } else {
                it->second += 1;
            }
        }
        for (auto const &[p, c] : mp) {
            if (c == 0) {
                res[0].push_back(p);
            } else if (c == 1) {
                res[1].push_back(p);
            }
        }
        std::sort(res[0].begin(), res[0].end());
        std::sort(res[1].begin(), res[1].end());
        return res;
    }
};