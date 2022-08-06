#include <string>
using std::string;

#include <algorithm>

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string ss = s + s;
            int i = 0, j = 1, k = 0;
            int sz = s.size();
            while (i < sz && j < sz && k < sz) {
                if (ss[i + k] == ss[j + k]) {
                    ++k;
                } else {
                    ss[i + k] > ss[j + k] ? i = i + 1 + k : j = j + 1 + k;
                    if (i == j) {
                        ++i;
                    }
                    k = 0;
                }
            }
            return ss.substr(std::min(i, j), sz);
        } else {
            std::sort(s.begin(), s.end());
            return s;
        }
    }
};