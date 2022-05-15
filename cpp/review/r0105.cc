#include <string>
using std::string;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first.size() > second.size()) {
            string tmp = first;
            first = second;
            second = tmp;
        }
        std::size_t fz{first.size()}, sz{second.size()};
        if (sz - fz > 1) {
            return false;
        }
        if (sz == fz) {
            std::size_t count = 0;
            for (std::size_t i{0};i < fz;++i) {
                if (first[i] != second[i]) {
                    ++count;
                }
            }
            return count < 2;
        }
        std::size_t x = 0;
        for (;x < fz;++x) {
            if (first[x] != second[x]) {
                break;
            }
        }
        string fs = x >= fz ? "" : first.substr(x);
        string ss = x + 1 >= sz ? "" : second.substr(x + 1);
        return x == fz || fs == ss;
    }
};