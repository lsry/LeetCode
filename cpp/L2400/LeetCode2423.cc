#include <string>
using std::string;
#include <array>

class Solution {
public:
    bool equalFrequency(string word) {
        std::array<int, 26> counts{{0}};
        for (char c : word) {
            counts[c - 'a'] += 1;
        }
        for (int i = 0;i < 26;++i) {
            if (counts[i] == 0) {
                continue;
            }
            counts[i] -= 1;
            bool equal{true};
            int count{0};
            for (int x : counts) {
                if (x == 0) {
                    continue;
                }
                if (count == 0) {
                    count = x;
                }
                if (count != x) {
                    equal = false;
                    break;
                }
            }
            if (equal) {
                return true;
            }
            counts[i] += 1;
        }
        return false;
    }
};