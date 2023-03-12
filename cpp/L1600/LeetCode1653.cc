#include <string>
using std::string;

class Solution {
public:
    int minimumDeletions(string s) {
        int ta{0}, tb{0};
        for (char const c : s) {
            c == 'a' ? ++ta : ++tb;
        }
        int a{0}, b{0};
        int count = std::min(ta, tb);
        for (char const c : s) {
            c == 'a' ? ++a : ++b;
            count = std::min(count, b + ta - a);
        }
        return count;
    }
};