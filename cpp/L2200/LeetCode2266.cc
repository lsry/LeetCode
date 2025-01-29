#include <string>
#include <vector>
using std::string;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int countTexts(string pressedKeys) {
        int pz = pressedKeys.size();
        std::vector<unsigned long long int> dp(pz + 1, 0ULL);
        dp[pz] = 1;
        for (int i = pz - 1;i >= 0;--i) {
            int t = 0;
            if (pressedKeys[i] == '7' || pressedKeys[i] == '9') {
                    t = i + 3;
                } else {
                    t = i + 2;
                }
            for (int j = i;j < pz && pressedKeys[j] == pressedKeys[i] && j <= t;++j) {
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
        return dp[0];
    }
};

int main() {
    Solution s;
    s.countTexts("444479999555588866");
}