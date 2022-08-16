#include <string>
using std::string;

class Solution {
public:
    int maxScore(string s) {
        std::size_t sz{s.size()};
        if (sz < 2) {
            return 0;
        }
        std::size_t zero{0}, one{0};
        for (char const &c : s) {
            c == '1' ? one += 1 : zero += 1;
        }
        int score = 0;
        zero = 0;
        for (std::size_t i{0};i < sz - 1;++i) {
            s[i] == '1' ? one -= 1 : zero += 1;
            score = std::max(score, int(one + zero));
        }
        return score;
    }
};