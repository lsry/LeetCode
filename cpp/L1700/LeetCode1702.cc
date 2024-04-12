#include <string>
using std::string;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int zi{-1}, N = binary.size();
        for (int i = 0;i < N;++i) {
            if (binary[i] == '0') {
                zi = i;
                break;
            }
        }
        if (zi == -1 || zi == N - 1) {
            return binary;
        }
        int one{0};
        for (int i = zi + 1;i < N;++i) {
            if (binary[i] == '1') {
                ++one;
            }
        }
        return string(N - 1 - one, '1') + "0" + string(one, '1');
    }
};