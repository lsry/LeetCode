#include <string>
using std::string;

class Solution {
public:
    string getSmallestString(string s) {
        int N = s.size();
        for (int i = 0;i < N - 1;++i) {
            int si = s[i] - '0';
            int sj = s[i + 1] - '0';
            if (si % 2 == sj % 2 && sj < si) {
                char c = s[i];
                s[i] = s[i + 1];
                s[i + 1] = c;
                break;
            }
        }
        return s;
    }
};