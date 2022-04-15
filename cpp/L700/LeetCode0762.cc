class Solution {
private:
    const int PRIMES = 0b10100000100010100010100010101100;

    int ones(int x) {
        int one = 0;
        while (x > 0) {
            ++one;
            x = x - (x & (-x));
        }
        return one;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left;i <= right;++i) {
            int one = ones(i);
            if ((PRIMES >> one) & 1 == 1) {
                ++count;
            }
        }
        return count;
    }
};