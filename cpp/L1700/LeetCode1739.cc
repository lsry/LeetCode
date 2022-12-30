class Solution {
public:
    int minimumBoxes(int n) {
        int cur = 1;
        int i = 1;
        while (n > cur) {
            n -= cur;
            ++i;
            cur += i;
        }
        cur = 1;
        int j = 1;
        while (n > cur) {
            n -= cur;
            ++j;
            cur ++;
        }
        return i * (i - 1) / 2 + j;
    }
};