#include <vector>
using std::vector;

#include <string>
using std::string;

#include <utility>

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<std::pair<char, std::size_t>> cc;
        std::size_t sz{s.size()};
        for (std::size_t i{0};i < sz;) {
            std::size_t j{i};
            while (j < sz && s[j] == s[i]) {
                ++j;
            }
            cc.push_back(std::make_pair(s[i], j - i));
            i = j;
        }
        std::size_t cz{cc.size()};
        int ans{0};
        for (string const &word : words) {
            std::size_t ci{0}, wi{0}, wz{word.size()};
            bool flag{true};
            while (wi < wz && ci < cz) {
                if (word[wi] != cc[ci].first) {
                    flag = false;
                    break;
                }
                std::size_t wj{wi};
                while (wj < wz && word[wj] == word[wi]) {
                    ++wj;
                }
                if (cc[ci].second < wj - wi || (cc[ci].second != wj - wi && cc[ci].second < 3)) {
                    flag = false;
                    break;
                }
                ++ci;
                wi = wj;
            }
            if (ci >= cz && wi >= wz && flag) {
                ++ans;
            }
        }
        return ans;
    }
};