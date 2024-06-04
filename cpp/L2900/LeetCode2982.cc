#include <array>
#include <string>
#include <utility>
#include <vector>
using std::string;

class Solution {
    void addToLen(std::array<int, 3> &lens, int len) {
        if (lens[2] < len) {
            lens[2] = len;
        }
        if (lens[1] < lens[2]) {
            std::swap(lens[1], lens[2]);
        }
        if (lens[0] < lens[1]) {
            std::swap(lens[0], lens[1]);
        }
    }
public:
    int maximumLength(string s) {
        std::vector<std::array<int, 3>> dp(26, std::array<int, 3>{0});
        int N = s.size();
        for (int i = 0;i < N;) {
            int j = i;
            while (j < N && s[j] == s[i]) {
                ++j;
            }
            int len = j - i;
            addToLen(dp[s[i] - 'a'], len);
            i = j;
        } 
        int ans{-1};
        for (std::array<int, 3> const &d : dp) {
            if (d[0] - 2 > 0) {
                ans = std::max(ans, d[0] - 2);
            }
            int x = std::min(d[0] - 1, d[1]);
            if (x > 0) {
                ans = std::max(ans, x);
            }
            if (d[2] > 0) {
                ans = std::max(ans, d[2]);
            }
        }
        return ans;
    }
};