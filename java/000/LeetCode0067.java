public class LeetCode0067 {
    public String addBinary(String a, String b) {
        if (a.length() > b.length()) {
            return addBinary(b, a);
        }
        int an = a.length(), bn = b.length();
        if (an == 0) {
            return b;
        }
        StringBuilder res = new StringBuilder();
        int forward = 0;
        for (int i = an - 1;i >= 0;--i) {
            int a1 = a.charAt(i) - '0';
            int b1 = b.charAt(i + bn - an) - '0';
            res.append((a1 + b1 + forward) % 2);
            forward = (a1 + b1 + forward) / 2;
        }
        int index = -1;
        while (index + bn - an >= 0) {
            int b1 = b.charAt(index + bn - an) - '0';
            res.append((b1 + forward) % 2);
            forward = (b1 + forward) / 2;
            --index;
        }
        if (forward > 0) {
            res.append('1');
        }
        return res.reverse().toString();
    }
}