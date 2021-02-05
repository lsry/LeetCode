package L1300;

public class LeetCode1370 {
    public String sortString(String s) {
        int[] chars = new int[26];
        for (char c : s.toCharArray()) {
            chars[c - 'a'] ++;
        }
        StringBuilder sb = new StringBuilder();
        boolean low = true;
        for (int i = 0;i < s.length();) {
            if (low) {
                for (int j = 0;j < 26;++j) {
                    if (chars[j] > 0) {
                        sb.append((char)(j + 'a'));
                        chars[j] -= 1;
                        ++i;
                    }
                }
            } else {
                for (int j = 25;j >= 0;--j) {
                    if (chars[j] > 0) {
                        sb.append((char)(j + 'a'));
                        chars[j] -= 1;
                        ++i;
                    }
                }
            }
            low = !low;
        }
        return sb.toString();
    }
}
