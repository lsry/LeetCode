package L700;

public class LeetCode0709 {
    public String toLowerCase(String s) {
        if (s == null) {
            return s;
        }
        char[] chs = s.toCharArray();
        for (int i = 0;i < chs.length;++i) {
            if (chs[i] >= 'A' && chs[i] <= 'Z') {
                chs[i] = (char)(chs[i] + 32);
            }
        }
        return String.valueOf(chs);
    }
}