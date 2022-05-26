#include <string>
using std::string;

#include <array>
using std::array;

#include <vector>
using std::vector;

class Solution {
private:
    int compare(string const &w1, string const &w2, array<int, 26> const &pos) {
        std::size_t w1z{w1.size()}, w2z{w2.size()};
        std::size_t mz{std::min(w1z, w2z)};
        for (std::size_t i{0};i < mz;++i) {
            if (pos[w1[i] - 'a'] > pos[w2[i] - 'a']) {
                return 1;
            } else if (pos[w1[i] - 'a'] < pos[w2[i] - 'a']) {
                return -1;
            }
        }
        return w1z > w2z ? 1 : (w1z == w2z ? 0 : -1);
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<int, 26> pos{{0}};
        for (std::size_t i{0};i < 26;++i) {
            char c = order[i];
            pos[c - 'a'] = i;
        } 
        std::size_t wz{words.size()};
        for (std::size_t i{1};i < wz;++i) {
            if (compare(words[i - 1], words[i], pos) == 1) {
                return false;
            }
        }
        return true;
    }
};