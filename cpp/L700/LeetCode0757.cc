#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        std::stable_sort(intervals.begin(), intervals.end(), [](vector<int> const &v1, vector<int> const &v2) -> bool {
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1];
            } else {
                return v1[0] < v2[0];
            }
        });
        int first{-1}, second{-1};
        int ans = 0;
        int vz = intervals.size();
        for (int i = vz - 1;i >= 0;--i) {
            if (first == -1 || intervals[i][1] < first) {
                ans += 2;
                first = intervals[i][0];
                second = intervals[i][0] + 1;
            } else if (second > intervals[i][1]) {
                ans += 1;
                if (first > intervals[i][0]) {
                    second = first;
                    first = intervals[i][0];
                } else {
                    second = intervals[i][0] + 1;
                }
            }
        }
        return ans;
    }
};