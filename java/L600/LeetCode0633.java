package L600;

public class LeetCode0633 {
    public boolean judgeSquareSum(int c) {
        int sqc = (int)Math.sqrt(c);
        for (int i = 0;i <= sqc;++i) {
            int j = c - i * i;
            int sqj = (int)Math.sqrt(j);
            if (sqj * sqj == j) {
                return true;
            }
        }
        return false;
    }
}
