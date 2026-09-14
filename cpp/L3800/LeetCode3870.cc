class Solution {
public:
    int countCommas(int n) {
        int count{0};
        if (n >= 1'000'000'000) {
            count += (n - 1'0000'000'000 + 1) * 3;
            n -= 1'000'000'000;
        }
        if (n >= 1'000'000) {
            count += (n - 1'000'000 + 1) * 2;
            n -= 1'000'000;
        }
        if (n >= 1000) {
            count += n - 1000 + 1;
        }
        return count;
    }
};
