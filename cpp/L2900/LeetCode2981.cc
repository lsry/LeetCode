#include <string>
#include <unordered_map>
using std::string;

class Solution {
public:
    int maximumLength(string s) {
        int ans{-1};
        int N = s.size();
        std::unordered_map<string, int> mp;
        for (int i = 0;i < N;) {
            int j = i;
            while (j < N && s[j] == s[i]) {
                ++j;
            }
            int len = j - i;
            for (int k = 0;k < len;++k) {
                mp[string(k + 1, s[i])] += len - k;
            }
            i = j;
        }
        for (auto const &[key, count] : mp) {
            if (count >= 3) {
                ans = std::max(ans, static_cast<int>(key.size()));
            }
        }
        return ans;
    }
};