#include <string>
using std::string;

#include <vector>

class Solution {
    bool check(string const text, int low, int high, int ln) {
        for (int i{0};i < ln;++i) {
            if (text[low + i] != text[high + 1 + i - ln]) {
                return false;
            }
        }
        return true;
    }
    int search(string const &text, int low, int high, std::vector<std::vector<int>> &dp) {
        if (low > high) {
            return 0;
        } else if (low == high) {
            return 1;
        } else if (dp[low][high] != -1) {
            return dp[low][high];
        }
        int r{1};
        for (int i{low};i < (high + low + 1) / 2;++i) {
            if (check(text, low, high, i + 1 - low)) {
                int x = search(text, i + 1, high + low - i - 1, dp);
                if (x >= 0) {
                    r = std::max(r, x + 2);
                }
            }
        }
        dp[low][high] = r;
        return r;
    }
public:
    int longestDecomposition(string text) {
        std::size_t tz{text.size()};
        if (tz < 2) {
            return tz;
        }
        std::vector<std::vector<int>> dp(tz, std::vector<int>(tz, -1));
        return search(text, 0, tz - 1, dp);
    }
};
