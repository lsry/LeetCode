package L800;

public class LeetCode0859 {
    public boolean buddyStrings(String s, String goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        int[][] counts = new int[2][26];
        int N = s.length();
        int diff = 0;
        for (int i = 0;i < N;++i) {
            char a = s.charAt(i);
            char b = goal.charAt(i);
            counts[0][a - 'a']++;
            counts[1][b - 'a']++;
            if (a != b) {
                ++diff;
            }
        }
        for (int i = 0;i < 26;++i) {
            if (counts[0][i] != counts[1][i]) {
                return false;
            }
        }
        if (diff == 0) {
            for (int count : counts[0]) {
                if (count > 1) {
                    return true;
                }
            }
        }
        return diff == 2;
    }
}