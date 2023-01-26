#include <string>
using std::string;

#include <vector>

class Solution {
    void splitSentence(string const s, std::vector<string> &vs) {
        std::size_t sz{s.size()};
        for (std::size_t i{0};i < sz;++i) {
            if (s[i] == ' ') {
                continue;
            }
            std::size_t j{i};
            while (j < sz && s[j] != ' ') {
                ++j;
            }
            vs.push_back(s.substr(i, j - i));
            i = j;
        }
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1 == sentence2) {
            return true;
        }
        std::vector<string> vs1, vs2;
        splitSentence(sentence1, vs1);
        splitSentence(sentence2, vs2);
        std::size_t sz1{vs1.size()}, sz2{vs2.size()};
        std::size_t i{0}, j{0};
        while (i < sz1 && i < sz2 && vs1[i] == vs2[i]) {
            ++i;
        }
        while (j < sz1 - i && j < sz2 - i && vs1[sz1 - j - 1] == vs2[sz2 - j - 1]) {
            ++j;
        }
        return i + j == std::min(sz1, sz2);
    }
};