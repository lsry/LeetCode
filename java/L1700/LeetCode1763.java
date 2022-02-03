package L1700;

import java.util.HashSet;

public class LeetCode1763 {
        public String longestNiceSubstring(String s) {
            HashSet<Character> chs = new HashSet<>();
            for (char c : s.toCharArray()) {
                chs.add(c);
            }
            int last = -1;
            for (int i = 0;i < s.length();++i) {
                char c = s.charAt(i);
                if (c >= 'a' && c <= 'z') {
                    char c1 = (char)(c - 32);
                    if (!chs.contains(c1)) {
                        last = i;
                        break;
                    }
                } else {
                    char c1 = (char)(c + 32);
                    if (!chs.contains(c1)) {
                        last = i;
                        break;
                    }
                }
            }
            if (last != -1) {
                String s1 = longestNiceSubstring(s.substring(0, last));
                String s2 = longestNiceSubstring(s.substring(last + 1, s.length()));
                return s1.length() >= s2.length() ? s1 : s2;
            } else {
                return s;
            }
        }

        public static void main(String[] args) {
            LeetCode1763 code = new LeetCode1763();
            code.longestNiceSubstring("YazaAay");
        }
}
