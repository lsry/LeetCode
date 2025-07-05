#include <algorithm>
#include <string>
using std::string;

class Solution {
    int iterDir(string const &s, char c1, char c2, int k) {
        int ans{0};
        int maxAns{0};
        int step{0};
        for (char c : s) {
            if (c == c1 || c == c2) {
                ++ans;
            } else if (step < k) {
                ++ans;
                ++step;
            } else {
                --ans;
            }
            maxAns = std::max(maxAns, ans);
        }
        return maxAns;
    }    
public:
    int maxDistance(string s, int k) {
        int ans{0};
        ans = std::max(iterDir(s, 'N', 'E', k), ans);
        ans = std::max(iterDir(s, 'N', 'W', k), ans);
        ans = std::max(iterDir(s, 'S', 'E', k), ans);
        ans = std::max(iterDir(s, 'S', 'W', k), ans);
        return ans;
    }
};