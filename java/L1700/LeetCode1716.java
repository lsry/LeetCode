package L1700;

public class LeetCode1716 {
    public int totalMoney(int n) {
        int div = n / 7, mod = n % 7;
        int a = 28 * div;
        if (div > 1) {
            a += 7 * (div - 1) * div / 2;
        }
        a += (2 * div + 1 + mod) * mod / 2;
        return a;
    }
}
