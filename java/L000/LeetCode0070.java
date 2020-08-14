package L000;

public class LeetCode0070 {
    public int climbStairs(int n) {
        int one = 0, two = 1;
        for (int i = 1;i <= n;++i) {
            int cur = one + two;
            one = two;
            two = cur;
        }
        return two;
    }
}