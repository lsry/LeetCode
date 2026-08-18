#include <algorithm>
#include <array>
#include <string>
using std::string;

class Solution {
public:
    string smallestPalindrome(string s) {
        std::array<int, 26> counts{0};
        for (char c : s) {
            counts[c - 'a'] ++;
        }
        string prefix;
        int single = -1;
        for (int i = 0;i < 26;++i) {
            if (counts[i] % 2 == 1) {
                single = i;
                counts[i] -= 1;
            }
            if (counts[i] == 0) {
                continue;
            }
            char c = static_cast<char>(i + 'a');
            prefix += string(counts[i] / 2, c);
        }

        string suffix(prefix);
        std::reverse(suffix.begin(), suffix.end());
        if (single >= 0) {
            char c = static_cast<char>(single + 'a');
            return prefix + c + suffix;
        }
        return prefix + suffix;
    }
};
