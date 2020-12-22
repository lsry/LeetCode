package L300;

public class LeetCode0389 {
    public char findTheDifference(String s, String t) {
        int[] letters = new int[26];
        for (char letter : s.toCharArray()) {
            letters[letter - 'a'] += 1;
        }
        for (char letter : t.toCharArray()) {
            if (letters[letter - 'a'] == 0) {
                return letter;
            } else {
                letters[letter - 'a'] -= 1;
            }
        }
        for (int i = 0;i < letters.length;++i) {
            if (letters[i] == 1) {
                return (char) ('a' + i);
            }
        }
        return 'a';
    }
}
