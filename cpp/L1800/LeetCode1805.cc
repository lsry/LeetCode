#include <unordered_set>
#include <string>
using std::string;

class Solution {
public:
    int numDifferentIntegers(string word) {
        std::unordered_set<string> set;
        std::size_t wz{word.size()};
        for (std::size_t i{0};i < wz;++i) {
            if (word[i] >= '1' && word[i] <= '9') {
                std::size_t j = i;
                while (j < wz && word[j] >= '0' && word[j] <= '9') {
                    ++j;
                }
                set.emplace(word.substr(i, j - i));
                i = j;
            } else if (word[i] == '0' && (i + 1 == wz || word[i + 1] < '0' || word[i + 1] > '9')) {
                set.emplace("0");
                ++i;
            }
        }
        return set.size();
    }
};