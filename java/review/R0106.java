public class R0106 {
    public String compressString(String S) {
        int len = S.length();
        if (S == null || len == 0) {
            return S;
        }
        StringBuilder sb = new StringBuilder();
        char c = S.charAt(0);
        int n = 1;
        for (int i = 1;i < len;++i) {
            char t = S.charAt(i);
            if (t == c) {
                ++n;
            } else {
                sb.append(c);
                sb.append(n);
                n = 1;
                c = t;
            }
        }
        sb.append(c);
        sb.append(n);
        return (sb.length() >= len) ? S : sb.toString();
    }
}