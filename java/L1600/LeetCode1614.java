package L1600;

public class LeetCode1614 {
    public int maxDepth(String s) {
        int max = 0;
        int cur = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                ++cur;
                max = Math.max(cur, max);
            } else if (c == ')') {
                --cur;
            }
        }
        return max;
    }
}
