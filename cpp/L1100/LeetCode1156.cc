#include <string>
using std::string;
#include <array>
#include <algorithm>

class Solution {
    int postModify(string const &text) {
        std::array<std::array<int, 26>, 2> counts{{0}};
        for (char c : text) {
            counts[1][c - 'a'] += 1;
        }
        std::size_t tz{text.size()};
        int ans{0};
        for (std::size_t i{0};i < tz;) {
            std::size_t j{i};
            int cid{text[i] - 'a'};
            while (j < tz && text[j] == text[i]) {
                ++j;
                counts[1][cid] -= 1;
            }
            if (j < tz && (counts[1][cid] > 0 || counts[0][cid] > 0)) {
                std::size_t k{j + 1};
                int post{0};
                while (k < tz && text[k] == text[i]) {
                    ++k;
                    ++post;
                }
                if (counts[0][cid] > 0 || counts[1][cid] > post) {
                    ans = std::max(ans, static_cast<int>(k - i));
                } else {
                    ans = std::max(ans, static_cast<int>(j - i + post));
                }
            } else {
                ans = std::max(ans, static_cast<int>(j - i));
            }
            while (i < j) {
                counts[0][cid] += 1;
                ++i;
            }
        }
        return ans;
    }
public:
    int maxRepOpt1(string text) {
        int f1{postModify(text)};
        std::reverse(text.begin(), text.end());
        int f2{postModify(text)};
        return std::max(f1, f2);
    }
};