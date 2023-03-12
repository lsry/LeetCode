#include <string>
using std::string;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int bz = blocks.size();
        int i = 0;
        int white = 0;
        while (i < k) {
            if (blocks[i] == 'W') {
                ++white;
            }
            ++i;
        }
        int ans = white;
        for (int j = 0;i < bz;++i,++j) {
            if (blocks[i] == 'W') {
                ++white;
            }
            if (blocks[j] == 'W') {
                --white;
            }
            ans = std::min(white, ans);
        }
        return ans;
    }
};