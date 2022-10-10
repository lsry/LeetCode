#include <string>
using std::string;

class Solution {
public:
    bool canTransform(string start, string end) {
        int sz = start.size();
        int si = 0, ei = 0;
        for (;si < sz;++si) {
            if (start[si] == 'X') {
                continue;
            }
            while (ei < sz && end[ei] == 'X') {
                ++ei;
            }
            if (ei >= sz || start[si] != end[ei] || start[si] == 'L' && si < ei || start[si] == 'R' && si > ei) {
                return false;
            } 
            ++ei;
        }
        while (ei < sz && end[ei] == 'X') {
            ++ei;
        }
        return ei == sz;
    }
};