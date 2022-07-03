class Solution {
    constexpr static int MOD = 1000000007;

    bool isPrime(int n) {
        for (int i = 2;i * i <= n;++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    unsigned long long factroy(int n) {
        unsigned long long res = 1;
        for (int i = 2;i <= n;++i) {
            res = (res * i) % MOD;
        }
        return res;
    }
public:
    int numPrimeArrangements(int n) {
        unsigned long long prime = 0;
        for (int i = 2;i <= n;++i) {
            if (isPrime(i)) {
                ++prime;
            }
        }
        return (int)((factroy(prime) * factroy(n - prime)) % MOD);
    }
};