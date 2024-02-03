#include <string>
using std::string;
#include <array>

class Solution {
    int findNextChar(std::array<int, 26> &counts, int index) {
        for (;index >= 0;--index) {
            if (counts[index] > 0) {
                counts[index] -= 1;
                return index;
            }
        }
        return -1;
    }
public:
    string repeatLimitedString(string s, int repeatLimit) {
        std::array<int, 26> counts{{0}};
        for (char const c : s) {
            counts[c - 'a'] += 1;
        }
        string r;
        for (int i = 25;i >= 0;--i) {
            int repeat{0};
            for (int j = 0;j < counts[i];++j) {
                if (repeat >= repeatLimit) {
                    int ix = findNextChar(counts, i - 1);
                    if (ix == -1) {
                        break;
                    } else {
                        r.push_back('a' + ix);
                        r.push_back('a' + i);
                        repeat = 1;
                    }
                } else {
                    r.push_back('a' + i);
                    ++repeat;
                }
            }
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.repeatLimitedString("cczazcc", 3);
    return 0;
}
