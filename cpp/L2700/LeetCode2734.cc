#include <string>
using std::string;

class Solution {
    char getPrevChar(char c) {
        return c == 'a' ? 'z' : c - 1;
    }
public:
    string smallestString(string s) {
        auto it{s.begin()};
        while (it != s.end() && *it == 'a') {
            ++it;
        }
        auto nt{it  == s.end() ? s.end() : it + 1};
        while (nt != s.end() && *nt != 'a') {
            ++nt;
        }
        bool flag = true;
        while (it != nt) {
            flag = false;
            *it = getPrevChar(*it);
            ++it;
        }
        if (flag) {
            char c = s[s.size() - 1];
            s[s.size() - 1] = getPrevChar(c);
        }
        return s;
    }
};

int main() {
    Solution s;
    s.smallestString("aa");
}