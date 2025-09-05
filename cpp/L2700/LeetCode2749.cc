class Solution {
    int ones(long long int n) {
        int one{0};
        while (n > 0) {
            if ((n & 1) == 1) {
                ++one;
            }
            n = n >> 1;
        }
        return one;
    }
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 == 0) {
            return 0;
        }      
        int step{1};
        for (;;++step) {
            long long int x = 1LL * num1 - step * 1LL * num2;
            if (x < step) {
                return -1;
            }
            int one = ones(x);
            if (step >= one) {
                break;
            }
        }
        return step;
    }
};