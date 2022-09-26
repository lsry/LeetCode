#include <vector>
using std::vector;
#include <array>
#include <algorithm>

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::array<int, 201> freqs{{0}};
        for (int num : nums) {
            freqs[num + 100]++;
        }
        vector<std::pair<int, int>> f;
        for (int i = 0;i < 201;++i) {
            if (freqs[i] > 0) {
                f.push_back({i, freqs[i]});
            }
        }
        std::stable_sort(f.begin(), f.end(), [](auto &p1, auto &p2) -> bool {
            if (p1.second != p2.second) {
                return p1.second < p2.second;
            } else {
                return p1.first > p2.first;
            }
        });
        vector<int> res;
        for (auto &p : f) {
            for (int i = 0;i < p.second;++i) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};