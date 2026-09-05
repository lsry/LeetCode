#include <string>
using std::string;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        std::string r;
        int N = s.size();
        for (int one{0}, low{0}, high{0};high < N;++high) {
            if (s[high] == '1') {
                ++one;
            }
            while (low < high && (one > k || s[low] == '0')) {
                if (s[low] == '1') {
                    --one;
                }
                ++low;
            }
            if (one == k) {
                std::string c = s.substr(low, high - low + 1);
                if (r.empty() || c.size() < r.size() || (c.size() == r.size() && c < r)) {
                    r = c;
                }
            }
        }
        return r;
    }
};
