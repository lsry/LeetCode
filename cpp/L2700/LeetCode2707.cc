#include <vector>
using std::vector;
#include <string>
using std::string;
#include <unordered_set>

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int N = s.size();
        vector<int> dp(N + 1, N + 1);
        dp[0] = 0;
        std::unordered_set<string> st(dictionary.begin(), dictionary.end());
        for (int i = 1;i <= N;++i) {
            for (int j = i - 1;j >= 0;--j) {
                string t{s.substr(j, i - j)};
                if (st.find(t) != st.end()) {
                    dp[i] = std::min(dp[i], dp[j]);
                } else {
                    dp[i] = std::min(dp[i], dp[j] + i - j);
                }
            }
        }
        return dp[N];
    }
};