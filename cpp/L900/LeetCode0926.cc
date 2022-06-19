#include <string>
using std::string;

#include <vector>
using std::vector;

#include <array>
using std::array;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        std::size_t sz{s.size()};
        if (sz < 2) {
            return 0;
        }
        vector<array<int, 2>> dp;  // dp[0]: 0, dp[1]: 1
        dp.push_back({0, 0});
        for (std::size_t i{0};i < sz;) {
            int j = i;
            while (j < sz && s[j] == s[i]) {
                ++j;
            }
            array<int, 2> cur;
            if (s[i] == '0') {
                cur[0] = j - i + dp[dp.size() - 1][0];
                cur[1] = dp[dp.size() - 1][1];
                dp.push_back(cur);
            } else {
                cur[0] = dp[dp.size() - 1][0];
                cur[1] = dp[dp.size() - 1][1] + j - i;
                dp.push_back(cur);
            }
            i = j;
        }
        int min = sz + 1;
        for (array<int, 2> cur : dp) {
            min = std::min(min, cur[1] + dp[dp.size() - 1][0] - cur[0]);
        }
        return min;
    }
};