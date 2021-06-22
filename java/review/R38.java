package review;

import java.util.HashSet;

public class R38 {
    public String[] permutation(String s) {
        if (s == null || s.length() == 0) {
            return new String[]{};
        }
        StringBuilder sBuilder = new StringBuilder();
        HashSet<String> res = new HashSet<>();
        boolean[] flags = new boolean[s.length()];
        trace(s, 0, res, flags, sBuilder);
        return res.toArray(new String[res.size()]);
    }

    private void trace(String s, int index, HashSet<String> res, boolean[] flags, StringBuilder sBuilder) {
        if (index == s.length()) {
            res.add(sBuilder.toString());
        }
        final int N = s.length();
        for (int i = 0;i < N;++i) {
            if (flags[i] == false) {
                flags[i] = true;
                sBuilder.append(s.charAt(i));
                trace(s, index + 1, res, flags, sBuilder);
                sBuilder.deleteCharAt(sBuilder.length() - 1);
                flags[i] = false;
            }
        }
    }
}