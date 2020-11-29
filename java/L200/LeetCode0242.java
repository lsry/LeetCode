package L200;

public class LeetCode0242 {
    public boolean isAnagram(String s, String t) {
        int[] chars = new int[26];
        for (char c : s.toCharArray()) {
            chars[c - 'a'] += 1;
        }
        for (char c : t.toCharArray()) {
            chars[c - 'a'] -= 1;
            if (chars[c - 'a'] < 0) {
                return false;
            }
        }
        for (int i : chars) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
}
