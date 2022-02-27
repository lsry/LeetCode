#include <vector>
using std::vector;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        std::size_t sz = bits.size();
        int idx = -1;
        for (std::size_t i = 0;i < sz;) {
            if (bits[i] == 1) {
                if (i + 1 >= sz) {
                    return false;
                }
                i += 2;
            } else {
                idx = i;
                i += 1;
            }
        }
        return idx == sz - 1;
    }
};