#include <string>
using std::string;
#include <array>
#include <algorithm>

class Solution {
    int mapChar(char c) {
        switch (c) {
        case 'Q':
            return 0;
        case 'W':
            return 1;
        case 'E':
            return 2; 
        default:
            return 3;
        }
    }
    bool balance(std::array<int, 4> &counts, int p) {
        for (int x : counts) {
            if (x > p) {
                return false;
            }
        }
        return true;
    }
public:
    int balancedString(string s) {
        std::array<int, 4> counts{{0}};
        for (char c : s) {
            counts[mapChar(c)] += 1;
        }
        int p = s.size() / 4;
        if (counts[1] == counts[0] && counts[2] == counts[0] && counts[3] == counts[0]) {
            return 0;
        }
        int ans = s.size();
        for (int low{0}, high{0};low < 4 * p;++low) {
            while (high < 4 * p && !balance(counts, p)) {
                counts[mapChar(s[high])] -= 1;
                ++high;
            }
            if (!balance(counts, p)) {
                break;
            }
            ans = std::min(ans, high - low);
            counts[mapChar(s[low])] += 1;
        }
        return ans;
    }
};