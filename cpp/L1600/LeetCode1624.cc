#include <string>
using std::string;
#include <array>
#include <algorithm>

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        std::array<int, 26> cp{{0}};
        std::fill(cp.begin(), cp.end(), -1);
        std::size_t sz{s.size()};
        int res{0};
        bool exist{false};
        for (std::size_t i{0};i < sz;++i) {
            int cx{s[i] - 'a'};
            if (cp[cx] != -1) {
                exist = true;
                res = std::max(res, (int)(i - cp[cx] - 1));
            } else {
                cp[cx] = i;
            }
        }
        return exist ? res : -1;
    }
};