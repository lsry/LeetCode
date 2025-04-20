class Solution {
    constexpr static long long int MOD{1'000'000'007};

    long long int myPow(long long int num, long long int count) {
        if (count < 1) {
            return 1LL;
        }
        if (count == 1) {
            return num;
        } else if (count == 2) {
            return num * num % MOD;
        } else if (count % 2 == 0) {
            long long int before = myPow(num, count / 2);
            return before * before % MOD;
        }
        long long int before = myPow(num, count - 1);
        return num * before % MOD;

    }

    long long int iterPow(long long int num, long long int count) {
        long long int ans{1LL}, mul{num};
        while (count > 0) {
            if (count % 2 == 1) {
                ans = ans * mul % MOD;
            }
            mul = mul * mul % MOD;
            count /= 2;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long int odd{n / 2};
        long long int even{n - odd};
        long long int n1{iterPow(4, odd)};
        long long int n2{iterPow(5, even)};
        return n1 * n2 % MOD;
    }
};