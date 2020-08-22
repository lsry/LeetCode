package L100;

public class LeetCode0125 {
    public boolean isPalindrome(String s) {
        if (s == null || s.length() <= 1) {
            return true;
        }
        StringBuilder sb = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                sb.append(ch);
            } else if (ch >= 'a' && ch <= 'z') {
                sb.append(ch);
            } else if (ch >= 'A' && ch <= 'Z') {
                sb.append((char)(ch + 32));
                //sb.append(Character.toUpperCase(ch))
            }
        }
        //System.out.println(sb.toString());
        int left = 0, right = sb.length() - 1;
        while (left < right) {
            if (sb.charAt(left) != sb.charAt(right)) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

    public static void main(String[] args) {
        new LeetCode0125().isPalindrome("A man, a plan, a canal: Panama");
    }
}