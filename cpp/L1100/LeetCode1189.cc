#include <array>

#include <string>
using std::string;

#include <limits>

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        std::array<int, 5> counts{0};
        for (auto &c : text) {
            if (c == 'b') {
                ++counts[0];
            } else if (c == 'a') {
                ++counts[1];
            } else if (c == 'l') {
                ++counts[2];
            } else if (c == 'o') {
                ++counts[3];
            } else if (c == 'n') {
                ++counts[4];
            }
        }
        int res = std::numeric_limits<int>::max();
        for (std::size_t i = 0;i < 5;++i) {
            if (i == 2 || i == 3) {
                res = std::min(res, counts[i] / 2);
            } else {
                res = std::min(res, counts[i]);
            }
        }
        return res;
    }
};