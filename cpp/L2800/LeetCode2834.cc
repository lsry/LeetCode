class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int minimumPossibleSum(int n, int target) {
        unsigned long long int sum{0ULL};
        unsigned long long int n1 = target / 2;
        if (n1 >= n) {
            sum = static_cast<unsigned long long int>(n) * (1ULL + n) / 2ULL;
            return static_cast<int>(sum % MOD);
        }
        sum = (static_cast<unsigned long long int>(n1) * (1ULL + n1) / 2ULL) % MOD;
        int n2 = n - n1;
        sum = (sum + ((static_cast<unsigned long long int>(n2) * (2ULL * target + n2 - 1ULL) / 2ULL) % MOD)) % MOD;
        return static_cast<int>(sum);
    }
};