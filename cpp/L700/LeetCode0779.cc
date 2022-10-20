#include <array>
class Solution {
private:
    constexpr static std::array<std::array<int, 2>, 2> arr{{{0, 1}, {1, 0}}};
    int trace(int index) {
        if (index == 1) {
            return 0;
        }
        int pIndex = index / 2;
        int pos = pIndex * 2 == index ? 0 : 1;
        int pRes = trace(pIndex);
        return arr[pRes][pos];
    }
public:
    int kthGrammar(int n, int k) {
        int index = (1 << (n - 1)) - 1 + k;
        return trace(index);
    }
};