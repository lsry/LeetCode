#include <vector>
using std::vector;
#include <algorithm>
#include <unordered_map>
#include <queue>

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        std::unordered_map<int, int> map;
        for (int code : barcodes) {
            map[code] += 1;
        }
        auto f{[](auto const &p1, auto const &p2) {
            return p1.second <= p2.second;
        }};
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(f)> pq(map.begin(), map.end(), f);
        vector<int> res;
        res.reserve(barcodes.size());
        while (!pq.empty()) {
            auto p1{pq.top()};
            pq.pop();
            if (res.size() > 0 && res.back() == p1.first && !pq.empty()) {
                auto p2{pq.top()};
                pq.pop();
                res.push_back(p2.first);
                p2.second -= 1;
                if (p2.second > 0) {
                    pq.push(p2);
                }
                pq.push(p1);
                continue;
            }
            res.push_back(p1.first);
            p1.second -= 1;
            if (!pq.empty()) {
                auto p2{pq.top()};
                pq.pop();
                res.push_back(p2.first);
                p2.second -= 1;
                if (p2.second > 0) {
                    pq.push(p2);
                }
            }
            if (p1.second > 0) {
                pq.push(p1);
            }
        }
        return res;
    }
};