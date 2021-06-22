package L400;

public class LeetCode0483 {
    public String smallestGoodBase(String n) {
        long val = Long.parseLong(n);
        int mMax = (int)Math.floor(Math.log(val) / Math.log(2));
        for (int i = mMax;i > 1;--i) {
            int k = (int)Math.pow(val, 1.0 / i);
            long mul = 1, sum = 1;
            for (int j = 1;j <= i;++j) {
                mul *= k;
                sum += mul;
            }
            if (sum == val) {
                return String.valueOf(k);
            }
        }
        return String.valueOf(val - 1);
    }
}
