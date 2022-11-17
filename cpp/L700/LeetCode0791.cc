#include <string>
using std::string;
#include <array>
#include <algorithm>

class Solution {
public:
    string customSortString(string order, string s) {
        std::array<int, 26> pos{};
        std::fill(pos.begin(), pos.end(), 28);
        for (std::size_t i{0};i < order.size();++i) {
            pos[order[i] - 'a'] = i;
        }
        std::stable_sort(s.begin(), s.end(), [&](auto const c1, auto const c2) -> bool {
            return pos[c1 - 'a'] < pos[c2 - 'b'];
        });
        return s;
    }
};