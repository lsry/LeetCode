package L300;

public class LeetCode0383 {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[][] counts = new int[2][26];
        for (char c : ransomNote.toCharArray()) {
            counts[0][c - 'a']++;
        }
        for (char c : magazine.toCharArray()) {
            counts[1][c - 'a']++;
        }
        for (int i = 0;i < 26;i++) {
            if (counts[0][i] > counts[1][i]) {
                return false;
            }
        }
        return true;
    }
}
