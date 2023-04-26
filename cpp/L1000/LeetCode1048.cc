#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>

class Solution {
    bool areaEqual(string const &longer, std::size_t llow, std::size_t lhigh, 
                   string const &shorter, std::size_t slow, std::size_t shigh) {
        if (lhigh - llow != shigh - slow) {
            return false;
        }
        for (std::size_t i{0};llow + i <= lhigh;++i) {
            if (longer[llow + i] != shorter[slow + i]) {
                return false;
            }
        }
        return true;
    }
    bool preBody(string const &longer, string const &shorter) {
        std::size_t llow{0}, lhigh{longer.size() - 1};
        std::size_t slow{0}, shigh{shorter.size() - 1};
        for (std::size_t i{0};slow + i <= shigh;++i) {
            if (longer[llow + i] != shorter[slow + i]) {
                return areaEqual(longer, llow + i + 1, lhigh, shorter, slow + i, shigh);
            }
        }
        return longer.size() == shorter.size() + 1;
    }
public:
    int longestStrChain(vector<string>& words) {
        std::size_t wz{words.size()};
        if (wz < 2) {
            return wz;
        }
        std::stable_sort(words.begin(), words.end(), [](string const &s1, string const &s2){
            return s1.size() <= s2.size();
        });
        vector<int> dp(wz, 1);
        int ans{1};
        for (std::size_t i{1};i < wz;++i) {
            for (int j = i - 1;j >= 0;--j) {
                if (words[j].size() == words[i].size()) {
                    continue;
                }
                if (words[j].size() + 1 != words[i].size()) {
                    break;
                }
                if (preBody(words[i], words[j])) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};