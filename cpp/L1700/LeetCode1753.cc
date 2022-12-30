class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int goal{0};
        do {
            int zero{0};
            if (a == 0) {
                zero += 1;
            }
            if (b == 0) {
                zero += 1;
            }
            if (c == 0) {
                zero += 1;
            }
            if (zero > 1) {
                break;
            }
            int t1{0}, t2{0}, t3{0};
            if (a >= b && a >= c) {
                t3 = a;
                if (b >= c) {
                    t1 = c;
                    t2 = b;
                }else {
                    t1 = b;
                    t2 = c;
                }
            } else if (b >= a && b >= c) {
                t3 = b;
                if (a >= c) {
                    t2 = a;
                    t1 = c;
                } else {
                    t2 = c;
                    t1 = a;
                }
            } else {
                t3 = c;
                if (a >= b) {
                    t2 = a;
                    t1 = b;
                } else {
                    t2 = b;
                    t1 = a;
                }
            }
            if (t1 > 0) {
                goal += t2 - (t1 - 1);
                t3 = t3 - t2 + (t1 - 1);
                t2 = t1 - 1;
            } else {
                goal += t2;
                t3 -= t2;
                t2 = 0;
            }
            a = t1;
            b = t2;
            c = t3;
        } while (true);
        return goal;
    }
};