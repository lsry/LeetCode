#include <cmath>
#include <numeric>

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};
public:
    int nthMagicalNumber(int n, int a, int b) {
        unsigned long long int mv{static_cast<unsigned long long int>(std::min(a, b))};
        unsigned long long int t{static_cast<unsigned long long int>(std::lcm(a, b))};
        unsigned long long int left{2ULL}, right{mv * n};
        while (left <= right) {
            unsigned long long int mid{left + (right - left) / 2ULL};
            unsigned long long int mi = mid / a + mid / b - mid / t;
            if (mi >= n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return (right + 1) % MOD;
    }
};