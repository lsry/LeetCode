#include <string>
using std::string;

class Solution {
public:
    int secondHighest(string s) {
        int a = -1, b = -1;
        for (char const c : s) {
            if (c >= '0' && c <= '9') {
                int x = c - '0';
                if (x == b) {
                    continue;
                }
                if (x > b) {
                    int t = x;
                    x = b;
                    b = t;
                }
                if (x > a) {
                    a = x;
                }
            }
        }
        return a;
    }
};