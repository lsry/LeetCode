#include <string>
using std::string;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int p1 = 0, p2 = 0;
        int N = text.size();
        for (char c : text) {
            if (c == pattern[0]) {
                ++p1;
            } else if (c == pattern[1]) {
                ++p2;
            }
        }
        if (pattern[0] == pattern[1]) {
            return 1LL * p1 * (p1 + 1) / 2;
        }
        long long cnt1 = p2, cnt2 = p1;
        for (char c : text) {
            if (c == pattern[0]) {
                cnt1 += p2;
            } else if (c == pattern[1]) {
                --p2;
            }
        }
        for (auto it{text.rbegin()};it != text.rend();++it) {
            if (*it == pattern[0]) {
                --p1;
            } else if (*it == pattern[1]) {
                cnt2 += p1;
            }
        }
        return std::max(cnt1, cnt2);
    }
};