#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        std::size_t n{intervals.size()};
        std::stable_sort(intervals.begin(), intervals.end(), [](vector<int> const &v1, vector<int> const &v2) {
            return v1[0] == v2[0] ? v1[1] <= v2[1] : v1[0] < v2[0];
        });
        for (std::size_t i{0};i < n;) {
            std::size_t j{i};
            int rmax{intervals[i][1]};
            while (j + 1 < n && intervals[j + 1][0] <= rmax) {
                ++j;
                rmax = std::max(rmax, intervals[j][1]);
            }  
            res.push_back({intervals[i][0], rmax});
            i = j + 1;
        }
        return res;
    }
};