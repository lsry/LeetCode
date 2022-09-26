class Solution {
private:
    bool isGoodNum(int n) {
        bool diff = false;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            if (d == 0 || d == 1 || d == 8) {
                continue;
            } else if (d == 2 || d == 5 || d == 6 || d == 9) {
                diff = true;
                continue;
            } else {
                return false;
            }
        }
        return diff;
    }
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1;i <= n;++i) {
            if (isGoodNum(i)) {
                ++count;
            }
        }
        return count;
    }
};