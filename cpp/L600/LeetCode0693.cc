class Solution {
public:
    bool hasAlternatingBits(int n) {
        int t = n & 1;
        while (n != 0) {
            if ((n & 1) != t) {
                return false;
            }
            n = n >> 1;
            t = 1 - t;
        }
        return true;
    }
};