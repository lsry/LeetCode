#include <string>
using std::string;
#include <array>
using std::array;
#include <numeric>

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        std::array<int, 26> counts{{0}};
        std::size_t pz{p.size()};
        for (std::size_t i{0}, j{0};j < pz;) {
            int cj = p[j] - 'a';
            if (i == j) {
                counts[cj] = std::max(counts[cj], 1);
                ++j;
            } else {
                int cj_1 = p[j - 1] - 'a';
                if ((cj_1 + 1) % 26 == cj) {
                    counts[cj] = std::max(counts[cj], int(j - i + 1));
                    ++j;
                } else {
                    i = j;
                }
            }
        }
        return std::accumulate(counts.begin(), counts.end(), 0);
    }
};