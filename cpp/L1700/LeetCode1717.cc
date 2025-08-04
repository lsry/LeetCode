#include <string>
#include <utility>
using std::string;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            std::swap(x, y);
            for (auto it{s.begin()};it != s.end();++it) {
                if (*it == 'a') {
                    *it = 'b';
                } else if (*it == 'b') {
                    *it = 'a';
                }
            }
        }      
        int ans{0};
        for (int i = 0;i < s.size();++i) {
            if (s[i] != 'a' && s[i] != 'b') {
                continue;
            }
            int a{0}, b{0};
            int j = i;
            for (;j < s.size() && (s[j] == 'a' || s[j] == 'b');++j) {
                if (s[j] == 'a') {
                    ++a;
                } else if (s[j] == 'b' && a > 0) {
                    --a;
                    ans += x;
                } else if (s[j] == 'b') {
                    ++b;
                }
            }
            i = j - 1;
            ans += std::min(a, b) * y;
        }
        return ans;
    }
};