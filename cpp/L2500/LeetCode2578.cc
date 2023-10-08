#include <algorithm>
#include <vector>
class Solution {
public:
    int splitNum(int num) {
        int a{0}, b{0};
        std::vector<int> bits;
        while (num != 0) {
            bits.push_back(num % 10);
            num /= 10;
        }
        std::sort(bits.begin(), bits.end());
        for (int i = 0;i < bits.size();++i) {
            if (i % 2 == 0) {
                a = a * 10 + bits[i];
            } else {
                b = b * 10 + bits[i];
            }
        }
        return a + b;
    }
};