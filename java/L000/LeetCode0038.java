package L000;
public class LeetCode0038 {
    public String countAndSay(int n) {
        String cur = "1";
        for (int i = 2;i <= n;++i) {
            StringBuilder sbBuilder = new StringBuilder();
            int len = cur.length();
            for (int j = 0;j < len;) {
                int t = 1;
                ++j;
                while (j < len && cur.charAt(j) == cur.charAt(j - 1)) {
                    ++t;
                    ++j;
                }
                sbBuilder.append(t);
                sbBuilder.append(cur.charAt(j - 1));
            }
            cur = sbBuilder.toString();
        }
        return cur;
    }
}
