package L000;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0093 {
    private List<String> res;
    public List<String> restoreIpAddresses(String s) {
        res = new ArrayList<>();
        if (s.length() < 4) {
            return res;
        }
        iter(new StringBuilder(), s, 0, 1);
        return res;
    }

    private void iter(StringBuilder sb,String str, int index,int count) {
        if (count > 4 || index >= str.length()) {
            return ;
        }
        if (count == 4) {
            if (str.charAt(index) == '0' && index != str.length() - 1) {
                return;
            }
            String cur = str.substring(index);
            try {
                int val = Integer.parseInt(cur);
                if (val >= 0 && val < 256) {
                    sb.append(val);
                    res.add(sb.toString());
                }
            } catch (Exception e) {
                return;
            }
            
        } else {
            for (int i = index + 1;i <= str.length() && i <= index + 3;++i) {
                if (i != index + 1 && str.charAt(index) == '0') {
                    break;
                }
                int val = Integer.parseInt(str.substring(index, i));
                if (val >= 0 && val < 256) {
                    StringBuilder sbt = new StringBuilder(sb);
                    sbt.append(val);
                    sbt.append('.');
                    iter(sbt, str, i, count + 1);
                }
            }
        }
    }
}