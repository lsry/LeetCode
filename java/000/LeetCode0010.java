public class LeetCode0010{
    public boolean isMatchTailToHead(String s, String p) {
        int slength = s.length(),plength = p.length();
        boolean match[][] = new boolean[slength+1][plength+1];
        match[slength][plength] = true;
        for (int si = slength;si >= 0;si--){
            for (int pj = plength - 1;pj >= 0;pj--){
                boolean first = si < slength && (p.charAt(pj) == '.' || p.charAt(pj) == s.charAt(si));
                if (pj+1 < p.length() && p.charAt(pj+1) == '*'){
                    match[si][pj] = first && match[si+1][pj] || match[si][pj+2];
                } else {
                    match[si][pj] = first && match[si+1][pj+1];
                }
            }
        }
        return match[0][0];
    }

    public boolean isMatch(String s, String p) {
        int SN = s.length(), PN = p.length();
        boolean flags[][] = new boolean[SN+1][PN+1];
        flags[0][0] = true;
        for (int si = 0;si <= SN;++si) {
            for (int pi = 1;pi <= PN;++pi) {
                if (p.charAt(pi - 1) == '*') {
                    if (match(s,si,p,pi - 1)) {
                        flags[si][pi] = flags[si - 1][pi] || flags[si][pi - 2];
                    } else {
                        flags[si][pi] = flags[si][pi - 2];
                    }
                } else {
                    if (match(s,si,p,pi)) {
                        flags[si][pi] = flags[si - 1][pi - 1];
                    }
                }
            }
        }
        return flags[SN][PN];
    }
    private boolean match(String s, int si, String p, int pi) {
        if (si == 0) {
            return false;
        }
        if (p.charAt(pi - 1) == '.') {
            return true;
        }
        return s.charAt(si - 1) == p.charAt(pi - 1);
    }

    public static void main(String[] args) {
        LeetCode0010 l10 = new LeetCode0010();
        System.out.println("1: " + (l10.isMatch("aa", "a") == false));
        System.out.println("2: " + (l10.isMatch("aa", "a*") == true));
        System.out.println("3: " + (l10.isMatch("ab", ".*") == true));
        System.out.println("4: " + (l10.isMatch("aab", "c*a*b*") == true));
    }
}