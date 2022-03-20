#include <fast_io.h>
#include <vector>
using std::vector;

#include <array>
using std::array;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int sz = data.size();
        if (sz == 0) {
            return true;
        }
        for (int i = 0;i < sz;) {
            int type = getType(data[i]);
            if (type < 0 || i + type >= sz) {
                return false;
            }
            for (int j = i + 1;j <= i + type;++j) {
                if ((data[j] & DATA_MASK[0]) != DATA_MASK[1]) {
                    return false;
                }
            }
            i = i + type + 1;
        }
        return true;
    }

private:
    const vector<vector<int>> MASK{{0b10000000, 0b11100000, 0b11110000, 0b11111000},
                                        {0b00000000, 0b11000000, 0b11100000, 0b11110000}};
    const array<int, 2> DATA_MASK{{0b11000000,  0b10000000}};
    int getType(int num) {
        for (int i = 3;i >= 0;--i) {
            if ((num & MASK[0][i]) == MASK[1][i]) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution code;
    vector<int> v{255};
    print(code.validUtf8(v), " ", true);
    return 0;
}