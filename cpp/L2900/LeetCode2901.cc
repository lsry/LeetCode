#include <algorithm>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <array>

class Solution {
    bool checkStr(string const &w1, string const &w2) {
        if (w1.size() != w2.size()) {
            return false;
        }
        int ans{0};
        for (int i = 0;i < w1.size();++i) {
            if (w1[i] != w2[i]) {
                ++ans;
            }
        }
        return ans == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int N = words.size();
        vector<std::array<int, 2>> dp(N, std::array<int, 2>{1, -1});
        int maxLength{1}, index{0};
        vector<vector<bool>> flags(N, vector<bool>(N, false));
        for (int i = 0;i < N;++i) {
            for (int j = i + 1;j < N;++j) {
                bool f = checkStr(words[i], words[j]);
                flags[i][j] = f;
                flags[j][i] = f;
            }
        }
        for (int i = 1;i < N;++i) {
            for (int j = i - 1;j >= 0;--j) {
                if (groups[i] != groups[j] && flags[i][j] && dp[j][0] + 1 > dp[i][0]) {
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = j;
                }
            }
            if (dp[i][0] > maxLength) {
                maxLength = dp[i][0];
                index = i;
            }
        }
        vector<string> ans;
        for (int i = index;i != -1;i = dp[i][1]) {
            ans.push_back(words[i]);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};