package L1800;

public class LeetCode1816 {
    public String truncateSentence(String s, int k) {
        int len = s.length();
        int i = 0;
        for (; i < len;++i) {
            while (i < len && s.charAt(i) != ' ') {
                ++i;
            }
            --k;
            if (k <= 0) {
                break;
            }
            ++i;
        }
        return s.substring(0, i);
    }
}
