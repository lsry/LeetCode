#include <string>
using std::string;

#include <set>

class Solution {
public:
    bool halvesAreAlike(string s) {
        std::set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        std::size_t sz{s.size()};
        std::size_t total(0), left{0};
        for (std::size_t i{0};i < sz;++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                ++total;
                if (i < sz / 2) {
                    ++left;
                }
            }
        }
        return total == 2 * left;
    }
};