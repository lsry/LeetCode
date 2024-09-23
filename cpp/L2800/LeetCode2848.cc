#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        std::sort(nums.begin(), nums.end(), [](vector<int> const &p1, vector<int> const &p2) {
            return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];
        });
        int start = 0, end = 0;
        int ans{0};
        for (vector<int> const &p : nums) {
            if (p[0] <= end) {
                if (p[1] >= end) {
                    end = p[1] + 1;
                }
                
            } else {
                ans += end - start;
                start = p[0];
                end = p[1] + 1;
            }
        }
        ans += end - start;
        return ans;
    }
};