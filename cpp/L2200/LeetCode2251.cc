#include <algorithm>
#include <cstddef>
#include <map>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        std::map<int, int> cnt; // 有序集合，保證讀取順序和按照key排序一致
        for (vector<int> const &f : flowers) {
            cnt[f[0]] += 1;
            cnt[f[1] + 1] -= 1;
        }      
        std::size_t pz{people.size()};
        vector<int> ptmp(pz);
        std::iota(ptmp.begin(), ptmp.end(), 0);
        std::sort(ptmp.begin(), ptmp.end(), [&](int a, int b) {
            return people[a] < people[b];
        });
        vector<int> res(pz, 0);
        auto it{cnt.begin()};
        int cur{0};
        for (std::size_t i{0};i < pz;++i) {
            int cur{0};
            for (;it != cnt.end() && it->first <= people[ptmp[i]];++it) {
                cur += it->second;
            }
            res[ptmp[i]] = cur;
        }
        return res;
    }
};