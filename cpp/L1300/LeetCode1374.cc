#include <string>
using std::string;

class Solution {
public:
    string generateTheString(int n) {
        if (n % 2 == 1) {
            return string(n, 'a');
        }
        string s(n - 1, 'a');
        s.push_back('b');
        return s;
    }
};