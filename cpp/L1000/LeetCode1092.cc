#include <string>
using std::string;
#include <vector>

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        std::size_t n1{str1.size()}, n2{str2.size()};
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
        for (std::size_t i{1};i <= n1;++i) {
            for (std::size_t j{1};j <= n2;++j) {
                if (str1[i - 1] != str2[j - 1]) {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
        string seq{""};
        for (std::size_t i{n1}, j{n2};i > 0 && j > 0;--i, --j) {
            while (i > 0 && j > 0 && str1[i - 1] != str2[j - 1]) {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    --i;
                } else {
                    --j;
                }
            }
            if (i == 0 || j == 0) {
                break;
            }
            seq.push_back(str1[i - 1]);
        }
        auto it1{str1.begin()}, it2{str2.begin()}; 
        string res{""};
        for (auto its{seq.rbegin()};its != seq.rend();++its) {
            while (it1 != str1.end() && *it1 != *its) {
                res.push_back(*it1);
                ++it1;
            }
            ++it1;
            while (it2 != str2.end() && *it2 != *its) {
                res.push_back(*it2);
                ++it2;
            }
            ++it2;
            res.push_back(*its);
        }
        while (it1 != str1.end()) {
            res.push_back(*it1);
            ++it1;
        }
        while (it2 != str2.end()) {
            res.push_back(*it2);
            ++it2;
        }
        return res;
    }
};