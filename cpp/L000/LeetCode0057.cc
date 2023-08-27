#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        std::size_t n{intervals.size()};
        std::size_t i{0};
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }
        if (i == n) {
            res.push_back(newInterval);
            return res;
        }
        if (newInterval[1] < intervals[i][0]) {
            res.push_back(newInterval);
        } else {
            int left{std::min(intervals[i][0], newInterval[0])}, right{std::max(newInterval[1], intervals[i][1])};
            ++i;
            while (i < n && intervals[i][0] <= right) {
                right = std::max(right, intervals[i][1]);
                ++i;
            }
            res.push_back({left, right});
        }
        while (i < n) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};