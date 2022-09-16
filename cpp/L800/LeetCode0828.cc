#include <vector>
using std::vector;

#include <string>
using std::string;

#include <array>

class Solution {
public:
    int uniqueLetterString(string s) {
        std::size_t sz{s.size()};
        vector<int> lefts(sz, -1), rights(sz, sz);
        std::array<int, 26> chars;
        std::fill(chars.begin(), chars.end(), -1);
        for (std::size_t i{0};i < sz;++i) {
            int px = s[i] - 'A';
            lefts[i] = chars[px];
            chars[px] = i;
        }
        std::fill(chars.begin(), chars.end(), sz);
        for (int i = sz - 1;i >= 0;--i) {
            int px = s[i] - 'A';
            rights[i] = chars[px];
            chars[px] = i;
        }
        int ans = 0;
        for (std::size_t i{0};i < sz;++i) {
            ans += (i - lefts[i]) * (rights[i] - i);
        }
        return ans;
    }
};