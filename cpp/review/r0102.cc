#include <string>
using std::string;
#include <array>

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        std::array<std::array<int, 26>, 2> arrs{{0}};
        for (const char c : s1) {
            arrs[0][c - 'a'] += 1;
        }
        for (const char c : s2) {
            arrs[1][c - 'a'] += 1;
        }
        for (std::size_t i{0};i < 26;++i) {
            if (arrs[0][i] != arrs[1][i]) {
                return false;
            }
        }
        return true;
    }
};