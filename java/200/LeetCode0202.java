import java.util.HashSet;
import java.util.Set;

public class LeetCode0202 {
    public boolean isHappy(int n) {
        Set<Integer> si = new HashSet<>();
        while (n != 1 && !si.contains(n)) {
            si.add(n);
            int sum = 0;
            while (n != 0) {
                int mod = n % 10;
                sum += mod * mod;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
}