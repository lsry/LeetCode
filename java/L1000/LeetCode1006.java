package L1000;

public class LeetCode1006 {
    public int clumsy(int N) {
        int res = mulDiv(N);
        int op = 1; 
        for (int i = N - 3;i > 0;op = (op + 1) % 2) {
            switch (op) {
                case 0: res -= mulDiv(i); i -= 3; break;
                case 1: res += i; --i; break;
            }
        }
        return res;
    }

    private int mulDiv(int n) {
        int r = n;
        if (n - 1 > 0) {
            r *= n - 1;
        }
        if (n - 2 > 0) {
            r /= n - 2;
        }
        return r;
    }
}
