#include <string>
#include <vector>
using std::string;

class Solution {
    int isPalindrome(string const &s, int left, int right) {
        int ans{0};
        while (left < right) {
            if (s[left] != s[right]) {
                ++ans;
            }
            ++left;
            --right;
        }
        return ans;
    }
public:
    int palindromePartition(string s, int k) {
        int N = s.size();
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(k + 1, -1));
        dp[0][0] = 0;
        for (int i = 1;i <= N;++i) {
            for (int k0 = 1;k0 <= std::min(i, k);++k0) {
                int ans{-1};
                for (int j = i;j >= 1;--j) {
                    if (dp[j - 1][k0 -1] != -1) {
                        int count = isPalindrome(s, j - 1, i - 1);
                        ans = ans == -1 ? count + dp[j - 1][k0 - 1] : std::min(ans, count + dp[j - 1][k0 - 1]);
                    }
                }
                dp[i][k0] = ans;
            }
        }
        return dp[N][k];         
    }
};

int main() {
    Solution s;
    s.palindromePartition("aabbc", 3);
}