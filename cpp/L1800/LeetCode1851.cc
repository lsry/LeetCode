#include <vector>
using std::vector;
#include <algorithm>
#include <queue>

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        std::stable_sort(intervals.begin(), intervals.end(), [](vector<int> const &v1, vector<int> const &v2) {
            return v1[0] <= v2[0];
        });
        int qz = queries.size();
        vector<int> r(qz, -1);
        vector<std::pair<int, int>> vp;
        vp.reserve(qz);
        for (int i = 0;i < qz;++i) {
            vp.emplace_back(std::make_pair(queries[i], i));
        }
        std::stable_sort(vp.begin(), vp.end(), [](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
            return p1.first <= p2.first;
        });
        auto f{[](vector<int> const &v1, vector<int> const &v2) {
            return v1[1] - v1[0] >= v2[1] - v2[0];
        }};
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(f)> pq(f);
        for (int q{0}, i{0};q < qz;++q) {
            while (i < intervals.size() && intervals[i][0] <= vp[q].first) {
                pq.push(intervals[i]);
                ++i;
            }
            while (!pq.empty() && pq.top()[1] < vp[q].first) {
                pq.pop();
            }
            if (!pq.empty()) {
                r[vp[q].second] = pq.top()[1] - pq.top()[0] + 1;
            }
        }
        return r;
    }
};
int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> vrr{{1,4},{2,4},{3,6},{4,4}};
    vector<int> vq{2,3,4,5};
    s.minInterval(vrr, vq);
    return 0;
}
