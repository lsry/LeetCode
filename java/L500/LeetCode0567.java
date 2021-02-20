package L500;

public class LeetCode0567 {
    public boolean checkInclusion(String s1, String s2) {
        final int n1 = s1.length(), n2 = s2.length();
        int[] sc1 = new int[26];
        for (char c : s1.toCharArray()) {
            sc1[c - 'a'] += 1;
        }
        int[] sc2 = new int[26];
        int i = 0, j = 0;
        while (j < n2 && j < n1) {
            sc2[s2.charAt(j) - 'a'] += 1;
            ++j;
        }
        while (j <= n2) {
            if (check(sc1, sc2)) {
                return true;
            }
            sc2[s2.charAt(i) - 'a'] -= 1;
            ++i;
            if (j >= n2) {
                break;
            }
            sc2[s2.charAt(j) - 'a'] += 1;
            ++j;
        }
        return false;
    }

    private boolean check(int[] c1, int[] c2) {
        for (int i = 0;i < c1.length;++i) {
            if (c1[i] != c2[i]) {
                return false;
            }
        }
        return true;
    }
}
