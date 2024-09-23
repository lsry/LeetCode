#include <string>
using std::string;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans{0};
        int N = s.size();
        for (int i = 0;i < N;) {
            int j = i + 1;
            while (j < N && s[j] - s[j - 1] == 1) {
                ++j;
            }
            ans = std::max(ans, j - i);
            i = j;
        }
        return ans;
    }
};