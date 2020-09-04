public class LeetCode0557 {
    public String reverseWords(String s) {
        char[] chars = s.toCharArray();
        int l = 0, r = 0;
        while(l < chars.length) {
            while (l < chars.length && Character.isWhitespace(chars[l])) {
                ++l;
            }
            r = l;
            while (r < chars.length && !Character.isWhitespace(chars[r])) {
                ++r;
            }
            for (int i = l, j = r;i < j;++i,--j) {
                char c = chars[i];
                chars[i] = chars[j - 1];
                chars[j - 1] = c;
            }
            l = r + 1;
        }
        return String.valueOf(chars);
    }

    public static void main(String[] args) {
        LeetCode0557 code = new LeetCode0557();
        code.reverseWords("Let's take LeetCode contest");
    }
}