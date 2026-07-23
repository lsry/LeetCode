#include <numeric>
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd{0}, sumEven{0};
        for (int i = 1, num{1};i <= n;++i) {
            sumOdd += num;
            sumEven += num + 1;
            num += 2;
        }
        return std::gcd(sumEven, sumOdd);

        // another method:
        // sumEven = n(2 + 2n) / 2 = n(n + 1)
        // sumOdd = n(1 + 2n - 1) / 2 = n * n
        // return n;
    }
};
