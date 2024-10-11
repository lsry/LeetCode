class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n < 2 ? 1.0 : 0.5;
    }
};