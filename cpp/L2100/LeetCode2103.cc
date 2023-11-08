#include <array>
#include <string>
using std::string;

class Solution {
public:
    int countPoints(string rings) {
        std::array<int, 10> flags{{0}};
        for (std::size_t i{0};i < rings.size();i += 2) {
            int id = rings[i + 1] - '0';
            if (rings[i] == 'R') {
                flags[id] |= 0b001;
            } else if (rings[i] == 'G') {
                flags[id] |= 0b010;
            } else {
                flags[id] |= 0b100;
            }
        }
        int ans{0};
        for (int f : flags) {
            if (f == 0b111) {
                ans += 1;
            }
        }
        return ans;
    }
};