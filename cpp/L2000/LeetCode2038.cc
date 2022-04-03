#include <string>
using std::string;

class Solution {
public:
    bool winnerOfGame(string colors) {
        std::size_t ca = 0, cb = 0;
        std::size_t sz = colors.size();
        for (std::size_t i = 0;i < sz;++i) {
            if (i + 1 < sz && i + 2 < sz && colors[i] == 'A' && colors[i + 1] == 'A'
                 && colors[i + 2] == 'A') {
                     ++ca;
            }
            if (i + 1 < sz && i + 2 < sz && colors[i] == 'B' && colors[i + 1] == 'B'
                 && colors[i + 2] == 'B') {
                     ++cb;
            }
        }
        return ca > cb;
    }
};