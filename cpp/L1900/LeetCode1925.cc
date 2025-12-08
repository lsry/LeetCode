#include <cmath>
class Solution {
public:
    int countTriples(int n) {
        int ans{0};
        for (int i = 1;i < n;++i) {
            for (int j = i;j < n;++j) {
                int square = i * i + j * j;
                int k = std::sqrt(square);
                if (k <= n && k * k == square) {
                    ans += i == j ? 1 : 2;
                }
            }
        }
        return ans;
    }
};
