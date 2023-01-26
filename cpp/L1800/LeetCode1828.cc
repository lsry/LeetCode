#include <vector>
using std::vector;

#include <cmath>

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for (vector<int> const &query : queries) {
            int ans{0};
            for (vector<int> &point : points) {
                int x{point[0] - query[0]}, y{point[1] - query[1]};
                if (std::sqrt(x * x + y * y) <= query[2] * 1.0) {
                    ++ans;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};