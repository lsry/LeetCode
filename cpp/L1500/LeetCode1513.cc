#include <string>
using std::string;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
    public:
    int numSub(string s) {
        int N = s.size();
        unsigned long long int ans{0};
        for (int i = 0;i < N;++i) {
            if (s[i] == '0') {
                continue;
            }
            int j{i};
            while (j < N && s[j] == '1') {
                ++j;
            }
            int one = j - i;
            ans = (ans + 1ULL * one * (one + 1) / 2) % MOD;
            i = j - 1;
        }
        return static_cast<int>(ans);
    }
};
