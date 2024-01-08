#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans{0};
        std::size_t pz{points.size()};
        std::unordered_map<int, int> map;
        for (std::size_t i{0};i < pz;++i) {
            for (std::size_t j{0};j < pz;++j) {
                int dis{(points[j][0] - points[i][0]) * (points[j][0] - points[i][0]) + (points[j][1] - points[i][1]) * (points[j][1] - points[i][1])};
                map[dis] += 1;
            }
            for (auto const &[k, v] : map) {
                ans += v * (v - 1);
            }
            map.clear();
        }
        return ans;
    }
};