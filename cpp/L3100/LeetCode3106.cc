#include <string>
using std::string;

class Solution {
    int charDistance(char x, char y) {
        int d = x < y ? y - x : x - y;
        return std::min(d, 26 - d);
    }
public:
    string getSmallestString(string s, int k) {
        for (auto it{s.begin()};it != s.end() && k > 0;++it) {
            for (char x{'a'};x <= 'z';++x) {
                int cd = charDistance(x, *it);
                if (cd <= k) {
                    *it = x;
                    k -= cd;
                    break;
                }
            }
        }
        return s;
    }
};