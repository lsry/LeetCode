#include <string>
using std::string;

class Solution {
public:
    int minInsertions(string s) {
        int lefts{0};
        int ans{0};
        int N = s.size();
        for (int i = 0;i < N;++i) {
            if (s[i] == '(') {
                ++lefts;
            } else if (s[i] == ')') {
                if (lefts > 0) {
                    --lefts;
                } else {
                    ++ans;
                }
                if (i + 1 < N && s[i + 1] == ')') {
                    ++i;
                } else {
                    ++ans;
                }
            }
        }
        return ans + 2 * lefts;
    }
};
