package L2000;

public class LeetCode2000 {
    public String reversePrefix(String word, char ch) {
        int i = 0;
        StringBuilder sBuilder = new StringBuilder();
        for (char c : word.toCharArray()) {
            sBuilder.append(c);
            if (c == ch) {
                break;
            }
            ++i;
        }
        if (i >= word.length()) {
            return word;
        }
        return sBuilder.reverse().toString() + word.substring(i + 1);
    }
}
