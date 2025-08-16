class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        int one{0};
        while (n > 0) {
            int m = n % 3;
            if (m == 2) {
                return false;
            } else if (m == 1) {
                ++one;
            }
            n /= 3;
        }
        return one == 1;
    }
};