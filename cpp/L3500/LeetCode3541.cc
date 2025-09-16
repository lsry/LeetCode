#include <array>
#include <string>
using std::string;

class Solution {
public:
    int maxFreqSum(string s) {
        std::array<int, 26> counts{0};
        for (char c : s) {
            counts[c - 'a']++;
        }      
        int vow{0}, other{0};
        for (int i = 0;i < 26;++i) {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
                vow = std::max(vow, counts[i]);
            } else {
                other = std::max(other, counts[i]);
            }
        }
        return vow + other;
    }
};