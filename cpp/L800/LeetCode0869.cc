#include <vector>
#include <array>
class Solution {
    std::vector<std::array<int, 10>> pows;
public:
    Solution() {
        for (int i = 0;i < 31;++i) {
            int cur = 1 << i;
            pows.emplace_back(std::array<int, 10>());
            while (cur != 0) {
                pows.back()[cur % 10] ++;
                cur /= 10;
            }
        }
    }
    bool reorderedPowerOf2(int n) {
        std::array<int, 10> na;
        while (n != 0) {
            na[n % 10]++;
            n /= 10;
        }
        for (std::array<int, 10> const &pow : pows) {
            bool flag{true};
            for (int i = 0;i < 10;++i) {
                if (na[i] != pow[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};