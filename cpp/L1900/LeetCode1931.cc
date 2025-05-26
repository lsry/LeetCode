#include <cmath>
#include <unordered_map>
#include <utility>
#include <vector>
class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};
public:
    int colorTheGrid(int m, int n) {
        int M = std::pow(3, m);
        std::unordered_map<int, std::vector<int>> numMap;
        for (int i = 0;i < M;++i) {
            std::vector<int> numVec(m, 0);
            for (int x = i, j = 0;j < m;++j) {
                numVec[j] = x % 3;
                x /= 3;
            }
            bool flag{true};
            for (int j = 1;j < m;++j) {
                if (numVec[j] == numVec[j - 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                numMap[i] = std::move(numVec);
            }
        }
        std::vector<std::vector<unsigned long long int>> dp(2, std::vector<unsigned long long int>(M, 0ULL));
        int curIndex{0};
        for (auto const &[num, numVec] : numMap) {
            dp[curIndex][num] = 1ULL;
        }
        for (int i = 1;i < n;++i) {
            int nextIndex = 1 - curIndex;
            for (auto const &[numA, vecA] : numMap) {
                dp[nextIndex][numA] = 0ULL;
                for (auto const &[numB, vecB] : numMap) {
                    bool flag{true};
                    for (int j = 0;j < m;++j) {
                        if (vecA[j] == vecB[j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        dp[nextIndex][numA] = (dp[nextIndex][numA] + dp[curIndex][numB]) % MOD;
                    }
                }
            }
            curIndex = nextIndex;
        }
        unsigned long long int ans{0ULL};
        for (auto const &[num, vec] : numMap) {
            ans = (ans + dp[curIndex][num]) % MOD;
        }
        return static_cast<int>(ans);
    }
};