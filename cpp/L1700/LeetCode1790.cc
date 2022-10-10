#include <string>
using std::string;
#include <vector>

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        std::size_t sz{s1.size()};
        std::vector<std::size_t> vz;
        for (std::size_t i{0};i < sz;++i) {
            if (s1[i] != s2[i]) {
                vz.push_back(i);
            }
        }
        if (vz.size() == 0) {
            return true;
        }
        if (vz.size() != 2) {
            return false;
        }
        return s1[vz[0]] == s2[vz[1]] && s2[vz[0]] == s1[vz[1]];
    }
};