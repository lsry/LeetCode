#include <string>
using std::string;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        std::size_t sz{sequence.size()}, wz{word.size()};
        if (sz == 0 || wz == 0) {
            return 0;
        }
        for (std::size_t i{sz / wz};i >= 1;--i) {
            string s;
            for (std::size_t j{0};j < i;++j) {
                s += word;
            }
            if (sequence.find(s) != string::npos) {
                return i;
            }
        }
        return 0;
    }
};