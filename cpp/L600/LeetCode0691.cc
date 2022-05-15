#include <vector>
using std::vector;

#include <array>
using std::array;

#include <string>
using std::string;

#include <functional>

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        std::size_t vz = stickers.size(), tz = target.size();
        vector<int> dp(1 << tz, -1);
        dp[(1 << tz) - 1] = 0;
        std::function<int(int)> helper = [&](int state) -> int {
            if (dp[state] != -1) {
                return dp[state];
            }
            int ans = tz + 1;
            for (string const & sticker : stickers) {
                int newState = state;
                std::array<int, 26> chars{{0}};
                for (char const &c : sticker) {
                    chars[c - 'a'] += 1;
                }
                for (std::size_t i{0};i < tz;++i) {
                    int ix = target[i] - 'a';
                    if (chars[ix] != 0 && ((newState >> i) & 1) != 1) {
                        --chars[ix];
                        newState |= (1 << i);
                    }
                }
                if (newState != state) {
                    ans = std::min(ans, helper(newState) + 1);
                }
            }
            dp[state] = ans;
            return ans;
        };
        helper(0);
        return dp[0] > tz ? -1 : dp[0];
    }
};