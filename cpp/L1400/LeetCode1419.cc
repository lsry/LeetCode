#include <string>
using std::string;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c{0}, r{0}, o{0}, a{0};
        int count{0};
        for (char const ch : croakOfFrogs) {
            if (ch == 'c') {
                ++c;
                count = std::max(count, c);
            } else if (ch == 'r') {
                if (r + 1 > c) {
                    return -1;
                }
                r += 1;
            } else if (ch == 'o') {
                if (o + 1 > r) {
                    return -1;
                }
                o += 1;
            } else if (ch == 'a') {
                if (a + 1 > o) {
                    return -1;
                }
                a += 1;
            } else if (ch == 'k') {
                if (!(a <= o && o <= r && r <= c)) {
                    return -1;
                }
                c -= 1;
                r -= 1;
                o -= 1;
                a -= 1;
            }
        }
        return c != 0 || r != 0 || o != 0 || a != 0 ? -1 : count;
    }
};