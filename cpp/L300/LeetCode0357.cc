class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 1;
        for (int i = 1;i <= n;++i) {
            int ct = 9;
            int fac = 9;
            for (int j = 2;j <= i;++j) {
                ct *= fac;
                fac -= 1;
            }
            count += ct;
        }
        return count;
    }
};