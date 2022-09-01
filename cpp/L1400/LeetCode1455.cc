#include <string>
using std::string;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        std::size_t wz{searchWord.size()}, sz{sentence.size()};
        int wi{1};
        for (std::size_t i{0};i < sz;) {
            if (sentence[i] == ' ') {
                ++wi;
                ++i;
                continue;
            } else if (sentence[i] == searchWord[0]) {
                bool flag{true};
                std::size_t j{0};
                for (;j < wz && i + j < sz;++j) {
                    if (sentence[i + j] != searchWord[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return wi;
                }
            }
            while (i < sz && sentence[i] != ' ') {
                ++i;
            }
        }
        return -1;
    }
};