#include <string>
#include <numeric>

class Solution {
public:
    int nextGreaterElement(int n) {
        std::string str = std::to_string(n);
        int nz = str.size();
        int x = nz - 1;
        for (;x > 0;--x) {
            if (str[x - 1] < str[x]) {
                break;
            }
        }
        if (x != 0) {
            int y = x;
            for (int j = y;j < nz;++j) {
                if (str[j] > str[x - 1]) {
                    y = j;
                }
            }
            char c = str[x - 1];
            str[x - 1] = str[y];
            str[y] = c;
        }
        for (int i = x, j = nz - 1;i < j;++i, --j) {
            char c = str[i];
            str[i] = str[j];
            str[j] = c;
        }
        unsigned long long num = 0;
        for (int i = 0;i < nz;++i) {
            num = num * 10 + (str[i] - '0');
        }
        return num > std::numeric_limits<int>::max() ? -1 : (int)num;
    }
};