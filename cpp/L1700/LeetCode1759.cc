#include <string>
using std::string;

class Solution {
    constexpr static unsigned long long int MOD = 1'000'000'007ULL;
public:
    int countHomogenous(string s) {
        unsigned long long int ans{0ULL}, cur{0ULL};
        std::size_t sz{s.size()};
        for (std::size_t i{0}, j{0};i < sz;) {
            j = i;
            while (j < sz && s[j] == s[i]) {
                ++j;
            }
            unsigned long long int count{j - i};
            i = j;
            count = count * (count + 1) / 2;
            ans = (ans + count) % MOD;
        }
        return static_cast<int>(ans);
    }
};