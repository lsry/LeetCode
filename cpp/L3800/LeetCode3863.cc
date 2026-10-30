#include <algorithm>
#include <string>
using std::string;

class Solution {
    bool is_sorted(string const &s) {
        for (int i = 1;i < s.size();++i) {
            if (s[i] < s[i - 1]) {
                return false;
            }
        }
        return true;
    }
public:
    int minOperations(string s) {
        if (is_sorted(s)) {
            return 0;
        }
        int N = s.size();
        if (N == 2) {
            return -1;
        }
        char minChar = 'z', maxChar = 'a';
        for (char c : s) {
            minChar = std::min(c, minChar);
            maxChar = std::max(c, maxChar);
        }
        if (s[0] == minChar || s[N - 1] == maxChar) {
            return 1;
        }
        for (int i = 1;i < N - 1;++i) {
            if (s[i] == minChar || s[i] == maxChar) {
                return 2;
            }
        }
        return 3;
    }
};
