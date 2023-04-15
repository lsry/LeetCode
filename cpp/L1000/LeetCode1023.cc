#include <string>
using std::string;
#include <vector>
using std::vector;
#include <cctype>

class Solution {
    bool check(string const &str, string const &p) {
        auto sb{str.begin()}, pb{p.begin()};
        while (sb != str.end() && pb != p.end()) {
            if (std::islower(*sb)) {
                if (*sb == *pb) {
                    ++sb;
                    ++pb;
                } else {
                    ++sb;
                }
            } else {
                if (*sb == *pb) {
                    ++sb;
                    ++pb;
                } else {
                    return false;
                }
            }
        }
        if (pb != p.end()) {
            return false;
        }
        while (sb != str.end()) {
            if (std::isupper(*sb)) {
                return false;
            }
            ++sb;
        }
        return true;
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        std::size_t qz{queries.size()};
        vector<bool> res(qz, false);
        for (std::size_t i{0};i < qz;++i) {
            res[i] = check(queries[i], pattern);
        }
        return res;
    }
};