#include <string>
using std::string;

class Solution {
public:
    int maxDepth(string s) {
        int ans{0};
        int left{0};
        for (char c : s) {
            if (c == '(') {
                ++left;
                ans = std::max(left, ans);
            } else if (c == ')') {
                --left;
            }
        }
        return ans;
    }
};
