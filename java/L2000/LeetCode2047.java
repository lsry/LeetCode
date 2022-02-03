package L2000;

import java.util.Arrays;

public class LeetCode2047 {
    public int countValidWords(String sentence) {
        if (sentence == null || sentence.length() == 0) {
            return 0;
        }
        String[] words = sentence.split("\\s+");
        return (int)Arrays.stream(words).filter(word -> {
            int hyphen = 0;
            int ln = word.length();
            if (ln == 0) {
                return false;
            }
            for (int i = 0;i < ln;++i) {
                char ch = word.charAt(i);
                if (Character.isDigit(ch)) {
                    return false;
                }
                if (i < ln - 1 && (ch == '.' || ch == ',' || ch == '!')) {
                    return false;
                }
                if (ch == '-') {
                    if (hyphen > 0) {
                        return false;
                    }
                    if (i - 1 < 0 || i + 1 >= ln || !(Character.isLetter(word.charAt(i + 1)) && Character.isLetter(word.charAt(i - 1)))) {
                        return false;
                    }
                    ++hyphen;
                }
            }
            return true;
        }).count();
    }

    public static void main(String[] args) {
        LeetCode2047 code = new LeetCode2047();
        code.countValidWords(" o6 t");
    }
}
