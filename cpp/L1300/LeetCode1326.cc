#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<std::pair<int, int>> poses(n + 1, std::pair<int,int>(0, 0));
        for (int i = 0;i <= n;++i) {
            poses[i].first = std::max(0, i - ranges[i]);
            poses[i].second = i + ranges[i];
        }
        std::stable_sort(poses.begin(), poses.end(), [&](std::pair<int, int> const &pa, std::pair<int, int> const &pb) {
            return pa.first <= pb.first;
        });
        int ans{0}, sr{-100}, cr{0};
        for (std::pair<int, int> const &pos : poses) {
            if (pos.first == pos.second || pos.second <= cr) {
                continue;
            }
            if (pos.first <= sr) {
                cr = std::max(cr, pos.second);
            } else if (pos.first <= cr) {
                sr = cr;
                cr = pos.second;
                ++ans;
            } else {
                return -1;
            }
            if (cr >= n) {
                break;
            }
        }
        return cr < n ? -1 : ans;
    }
};