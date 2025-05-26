#include <algorithm>
#include <array>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int N = words.size();
        vector<std::array<int, 2>> dp(N, std::array<int, 2>{1, -1});
        int maxLength{1}, index{0};
        for (int i = 1;i < N;++i) {
            for (int j = i - 1;j >= 0;--j) {
                if (groups[i] != groups[j] && dp[j][0] + 1 > dp[i][0]) {
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