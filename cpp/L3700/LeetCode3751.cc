#include <array>
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans{0};
        for (int i = std::max(num1, 101);i <= num2;++i) {
            std::array<int, 3> bit{-1, -1, -1};
            for (int id{0}, num{i};num != 0;num /= 10, ++id) {
                bit[id % 3] = num % 10;
                if (id >= 2) {
                    int x = bit[(id + 1) % 3];
                    int y = bit[(id + 2) % 3];
                    int z = bit[id % 3];
                    if ((y > x && y > z) || (y < x && y < z)) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};
