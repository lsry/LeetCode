class Solution {
    constexpr static long long int MAX_VALUE{1'000'000'000'000'000'000LL};
public:
    long long countCommas(long long n) {
        long long int count{0};
        for (long long int v{MAX_VALUE}, c{6};v > 0;v /= 1000, --c) {
            if (n < v) {
                continue;
            }
            long long int divisor = n / v;
            long long int mod = n % v;
            if (mod == v - 1) {
                count += divisor * v * c;
            } else {
                count += (mod + 1) * c + (divisor - 1) * v * c;
            }
            n = v - 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    s.countCommas(1004590);
}
