package L800;

public class LeetCode0844 {
    public boolean backspaceCompare(String S, String T) {
        int sn = S.length() - 1, tn = T.length() - 1;
        int sp = 0, tp = 0;
        while (sn >= 0 || tn >= 0) {
            while (sn >= 0) {
                if (S.charAt(sn) == '#') {
                    ++sp;
                    --sn;
                } else if (sp > 0) {
                    --sp;
                    --sn;
                } else {
                    break;
                }
            }
            while (tn >= 0) {
                if (T.charAt(tn) == '#') {
                    ++tp;
                    --tn;
                } else if (tp > 0) {
                    --tp;
                    --tn;
                } else {
                    break;
                }
            }
            if (sn >= 0 && tn >= 0) {
                if (S.charAt(sn) != T.charAt(tn)) {
                    return false;
                } else {
                    --sn;
                    --tn;
                }
            } else if (sn >= 0 || tn >= 0) {
                return false;
            }
        }
        return true;
    }
}
