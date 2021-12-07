package L1400;

public class LeetCode1446 {
    /**
     * 双指针：定义左右变量 i, j,
     * 外层循环做基本保证，内层循环遍历在条件满足的情况下，递增右指针
     */
    public int maxPower(String s) {
        int max = 0;
        int i = 0, j = 1;
        for (;j < s.length();++j) {
            if (s.charAt(i) != s.charAt(j)) {
                max = Math.max(max, j - i);
                i = j;
            }
        }
        max = Math.max(max, s.length() - i);
        return max;
    }
}