class Solution {
public:
    int alternateDigitSum(int n) {
        int odd{0}, even{0}, bit{0};
        for (bool pos{true};n != 0;n /= 10, pos = !pos) {
            int x{n % 10};
            odd += pos ? x : (-1 * x);
            even += !pos ? x : (-1 * x);
            bit++;
        }
        return bit % 2 != 0 ? odd : even;
    }
};