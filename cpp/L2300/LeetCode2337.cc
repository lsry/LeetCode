#include <cstddef>
#include <string>
using std::string;

class Solution {
public:
    bool canChange(string start, string target) {
       std::size_t n{start.size()};
       int sL{0}, sR{0}, tL{0}, tR{0};
       int i{0}, j {0};
       for (;j < n;++j) {
            if (target[j] == '_') {
                continue;
            }
            if (target[j] == 'R') {
                tR += 1;
                while (i <= j) {
                    if (start[i] == '_') {
                        ++i;
                        continue;
                        
                    }
                    if (start[i] == 'L') {
                        return false;
                    }
                    sR += 1;
                    ++i;
                }
                if (sR < tR) {
                    return false;
                }
            } else {
                while (i < j) {
                    if (start[i] == 'L') {
                        sL += 1;
                    } else if (start[i] == 'R') {
                        sR += 1;
                    }
                    ++i;
                }
                if (sL != tL || sR != tR) {
                    return false;
                }
                tL += 1;
                while (i < n && sL < tL) {
                    if (start[i] == 'R') {
                        return false;
                    } else if (start[i] == 'L') {
                        sL += 1;
                    }
                    ++i;
                }
                if (sL != tL) {
                    return false;
                }
            }
       } 
       if (sL != tL || sR != tR) {
        return false;
       }
       for (;i < n;++i) {
        if (start[i] == 'R' || start[i] == 'L') {
            return false;
        }
       }
       return true;
    }
};