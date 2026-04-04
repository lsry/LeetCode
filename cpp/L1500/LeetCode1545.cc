/**
 * 计算长度：
 * An+1 = 2An + 1
 * An+1 + 1 = 2An + 2 = 2(An + 1)
 * An + 1 = 2^n
 * An = 2^n - 1
 */
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n <= 1) {
            return '0';
        }
        bool inverted{false};
        for (;n > 1;--n) {
            int len = (1 << n) - 1;
            int mid = len / 2 + 1;
            if (k == mid) {
                break;
            } else if (k > mid) {
                inverted = !inverted;
                k = len / 2 - (k - mid) + 1;
            }
        }
        if (n == 1) {
            return inverted ? '1' : '0';
        } else {
            return inverted ? '0' : '1';
        }
    }
};
