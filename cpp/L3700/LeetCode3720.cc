#include <array>
#include <string>
using std::string;

class Solution {
    int compareString(std::array<int, 26> &cs, string const &target, string &r) {
        int ci{0};
        for (;ci < target.size();++ci) {
            int cx = target[ci] - 'a';
            if (cs[cx] == 0) {
                break;
            }
            r.push_back(target[ci]);
            cs[cx]--;
        }
        return ci;
    }

    int findPrefix(std::array<int, 26> &cs, string const &target, string &r, int cx) {
        if (cx == target.size()) {
            --cx;
            cs[r.back() - 'a']++;
            r.pop_back();
        }
        for (;cx >= 0;--cx) {
            for (int ix = target[cx] - 'a' + 1;ix < 26;++ix) {
                if (cs[ix] > 0) {
                    cs[ix]--;
                    r.push_back(static_cast<char>('a' + ix));
                    return cx;
                }
            }
            if (!r.empty()) {
                cs[r.back() - 'a']++;
                r.pop_back();
            }
        }
        return -1;
    }

public:
    string lexGreaterPermutation(string s, string target) {
        std::array<int, 26> cs{0};
        for (char c : s) {
            cs[c - 'a']++;
        }
        string r;
        int compareIndex = compareString(cs, target, r);
        compareIndex = findPrefix(cs, target, r, compareIndex);
        if (compareIndex == -1) {
            return "";
        }
        for (int i = 0;i < 26;++i) {
            for (int j = 0;j < cs[i];++j) {
                r.push_back(static_cast<char>('a' + i));
            }
        }
        return r;
    }
};
